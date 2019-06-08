/*
Copyright 2019 Neijwiert

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

namespace RenSharpExamplePlugin
{
    /*
    Automatic loading of event classes and other classes (such as a console function or game feature) can be disabled when the class is marked with the RenSharpIgnoreAttribute.
    The same goal can be achieved when the class isn't publicly defined.
    This can be useful if you need to delay loading, or when you have a constructor with arguments.
    Manual loading can be done by calling AttachToUnmanagedObject() and  RegisterManagedObject() right after instantiating the class
    */
    [RenSharpIgnore]
    public class IgnoredExampleEventClass : RenSharpEventClass
    {
        public IgnoredExampleEventClass()
        {
            Engine.ConsoleOutput($"{nameof(IgnoredExampleEventClass)}.{nameof(IgnoredExampleEventClass)} This is never called\n");
        }

        public override void UnmanagedAttach()
        {
            Engine.ConsoleOutput($"{nameof(IgnoredExampleEventClass)}.{nameof(UnmanagedAttach)} This is never called\n");
        }
    }
}
