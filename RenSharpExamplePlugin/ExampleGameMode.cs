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

namespace RenSharpExamplePlugin
{
    public class ExampleGameModePlayerData : RenSharpPlayerDataClass
    {
        public ExampleGameModePlayerData()
        {

        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        public override void UnmanagedAttach()
        {

        }

        public override void Init()
        {

        }

        public override void ClearLevel()
        {

        }

        public override void ClearSession()
        {

        }
    }

    // Game modes can also handle multiple inheritance use RenSharpGameModeClass, RenSharpGameModeEventClass or RenSharpGameModeEventClassPlayerDataFactory
    public class ExampleGameMode : RenSharpGameModeEventClassPlayerDataFactory<ExampleGameModePlayerData>
    {
        public ExampleGameMode()
        {
            
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        public override void UnmanagedAttach()
        {
            
        }

        public override void Init()
        {
            
        }
    }
}
