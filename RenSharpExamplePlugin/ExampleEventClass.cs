/*
Copyright 2020 Neijwiert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

using RenSharp;
using System;
using System.Drawing;

namespace RenSharpExamplePlugin
{
    // Inherit from RenSharpEventClass
    // This class will get automatically instantiated since it can be instantiated with parameterless construction
    // Also it needs to marked `public`.
    // To prevent automatic instantiation, have a complex constructor or do not mark it `public` or use the RenSharpIgnore attribute
    // To do custom registration, instantiate your EventClass, call InitUnmanagedAttachable() right after instantiating the class
    // The same attaching/registration process applies to all custom classes (such as game features, game modes). With the exception of global chat commands and key hooks.
    public class ExampleEventClass : RenSharpEventClass
    {
        // Called when automatically instantiated
        // At this point this event class is NOT bound to an unmanaged pointer of DAEventClass, so you may not call any member methods that interact with that pointer
        public ExampleEventClass()
        {
            
        }

        // Always called when the FDS exits and this class is registered internally. 
        // It is not called when the FDS crashes due to an exception
        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing); // MUST call bade dispose
        }

        // This method is called as soon as this class is bound to an unmanaged pointer of DAEventClass
        // It is not safe to call member functions that interact with that pointer. 
        // However, this class is at this point not internally registered, which happens after this method's call
        public override void UnmanagedAttach()
        {
            RegisterEvent(DAEventType.DALog);
            RegisterEvent(DAEventType.Refill, uint.MaxValue); //Using a priority of uint.MaxValue insures we can block these event before something else implements them.
            RegisterEvent(DAEventType.Suicide, uint.MaxValue);
            RegisterEvent(DAEventType.TeamChangeRequest, uint.MaxValue);
            RegisterObjectEvent(DAObjectEventType.Created, DAObjectEventObjectType.All); // Object events can specify what kind of object this event should trigger to

            RegisterChatCommand(TestChatCommand, "!test", 0); // Register chat command !test. This command gets removed as soon as this event class is disposed

            StartTimer(1, TimeSpan.FromSeconds(5), true, "This is a test string"); // Start a timer. We can pass any System.Object as our data object
        }

        bool TestChatCommand(IcPlayer player, string command, IDATokenClass text, TextMessageEnum chatType, object data)
        {
            Engine.SendMessage(Color.Green, "Hello there!");

            return true; // Show the command in chat. False is for hiding it
        }

        public override void DALogEvent(string header, string output)
        {
            Engine.ConsoleOutput($"{nameof(ExampleEventClass)}.{nameof(DALogEvent)}: {header} {output}.\n");
        }

        public override bool RefillEvent(IcPlayer player)
        {
            return false; // Block all refills
        }

        public override bool SuicideEvent(IcPlayer player)
        {
            return false; // Block all suicides
        }

        public override bool TeamChangeRequestEvent(IcPlayer player)
        {
            return false; //Block team change requests. This will catch both the team change button and the rtc command.
        }

        public override void ObjectCreatedEvent(IScriptableGameObj obj)
        {
            Engine.ConsoleOutput($"{nameof(ExampleEventClass)}.{nameof(ObjectCreatedEvent)}: Created object {obj.Definition}.\n");
        }

        public override void TimerExpired(int number, object data)
        {
            if (number == 1)
            {
                Engine.ConsoleOutput($"{nameof(ExampleEventClass)}.{nameof(TimerExpired)}: Timer expired {nameof(number)}={number}, {nameof(data)}='{data}'.\n");
            }
        }
    }
}
