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
    // A console function needs to inherit from RenSharpConsoleFunctionClass
    // Managed console functions can also use timers
    public class ExampleConsoleFunction : RenSharpConsoleFunctionClass
    {
        public ExampleConsoleFunction() 
            : base("example", "EXAMPLE - An example managed console function") // The name and help MUST not be null
        {

        }

        // Called when the FDS shuts down, but not when it crashes
        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing); // MUST call base dispose
        }

        public override void UnmanagedAttach()
        {
            
        }

        // Called when activated in the FDS
        public override void Activate(string pArgs)
        {
            Engine.ConsoleOutput($"{nameof(ExampleConsoleFunction)}.{nameof(Activate)}: with args '{pArgs}'.");
        }

        // Called right after the 'normal' activate, except it gives you the arguments as a IDATokenClass
        public override void Activate(IDATokenClass args)
        {
            
        }
    }
}
