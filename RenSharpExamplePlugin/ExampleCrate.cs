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
using System.Drawing;

namespace RenSharpExamplePlugin
{
    // Crate implementation
    public class ExampleCrate : RenSharpCrateClass
    {
        public ExampleCrate()
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
            base.Init(); // Base init should be called
        }

        public override void SettingsLoaded()
        {
            base.SettingsLoaded(); // Base settings loaded should be called
        }

        public override void CalculateOdds(IcPlayer player)
        {
            // You could determine custom odds here
            base.CalculateOdds(player);
        }

        public override bool CanActivate(IcPlayer player)
        {
            // You could determine if the current player can use this crate
            return !player.GameObj.IsStealthEnabled;
        }

        public override void Activate(IcPlayer player)
        {
            // Activates the crate
            Engine.SendMessagePlayer(player.Owner.Ptr, Color.Pink, "LOLOL");
        }
    }
}
