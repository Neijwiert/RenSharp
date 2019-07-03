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

using System;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security;

namespace RenSharp
{
    // TODO: w3d.h
    public sealed class RenSharpAppDomainManager : AppDomainManager, IRenSharpInterface
    {
        public override void InitializeNewDomain(AppDomainSetup appDomainInfo)
        {
            InitializationFlags = AppDomainManagerInitializationOptions.RegisterWithHost;
        }

        public void FreePointer(IntPtr ptr)
        {
            Marshal.FreeHGlobal(ptr);
        }

        public bool Init()
        {
            try
            {
                if (!Engine.Init())
                {
                    return false;
                }

                var threadManager = new RenSharpThreadManager();
                threadManager.AttachToUnmanagedObject();
                threadManager.RegisterManagedObject();

                var timerManager = new RenSharpTimerManager();
                timerManager.AttachToUnmanagedObject();
                timerManager.RegisterManagedObject();

                var chatCommandManager = new RenSharpChatCommandManager();
                chatCommandManager.AttachToUnmanagedObject();
                chatCommandManager.RegisterManagedObject();

                var keyHookManager = new RenSharpKeyHookManager();
                keyHookManager.AttachToUnmanagedObject();
                keyHookManager.RegisterManagedObject();

                var renSharpChatCommand = new RenSharpChatCommand();
                renSharpChatCommand.RegisterManagedObject();

                string renSharpText = $"| RenSharp {Engine.RenSharpVersion} with Dragonade {DA.Version} and Scripts {Engine.GetTTVersion().ToString("0.0", CultureInfo.InvariantCulture)} |";
                string createdText = "| Created by Neijwiert";

                Engine.ConsoleOutput($"\n{new string('-', renSharpText.Length)}\n");
                Engine.ConsoleOutput($"{renSharpText}\n");
                Engine.ConsoleOutput($"{createdText}{new string(' ', renSharpText.Length - createdText.Length - 1)}|\n");
                Engine.ConsoleOutput($"{new string('-', renSharpText.Length)}\n");

                IINISection pluginsSection = DASettingsManager.GetSection("RenSharpPlugins");
                if (pluginsSection == null)
                {
                    Engine.ConsoleOutput("| No plugins found\n");
                }
                else
                {
                    foreach (IINIEntry entry in pluginsSection.EntryList)
                    {
                        string entryValue = entry.Value;
                        if (entryValue != null)
                        {
                            if (entryValue.StartsWith("1", StringComparison.InvariantCultureIgnoreCase) || entryValue.StartsWith("true", StringComparison.InvariantCultureIgnoreCase))
                            {
                                string entryKey = entry.Entry;
                                if (entryKey != null)
                                {
                                    LoadPlugin(entryKey);
                                }
                            }
                        }
                    }
                }

                Engine.ConsoleOutput("\n");

                return true;
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(Init)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void Shutdown()
        {
            try
            {
                Engine.Shutdown();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(Shutdown)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassDestructed(IntPtr eventClass)
        {
            try
            {
                DAEventManager.OnManagedEventClassDestructed(eventClass);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassSettingsLoadedEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.SettingsLoadedEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassSettingsLoadedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassChatEvent(IntPtr eventClass, IntPtr player, TextMessageEnum type, string message, int receiverID)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.ChatEvent(cPlayer, type, message, receiverID);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassChatEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassChatCommandEvent(IntPtr eventClass, IntPtr player, TextMessageEnum type, string command, IntPtr text, int receiverID)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IDATokenClass daTokenClass = (text == IntPtr.Zero ? null : new DATokenClass(text));

                return mEventClass.ChatCommandEvent(cPlayer, type, command, daTokenClass, receiverID);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassChatCommandEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassKeyHookEvent(IntPtr eventClass, IntPtr player, string key)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.KeyHookEvent(cPlayer, key);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassKeyHookEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassHostChatEvent(IntPtr eventClass, int id, TextMessageEnum type, string message)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                return mEventClass.HostChatEvent(id, type, message);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassHostChatEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassRadioEvent(IntPtr eventClass, IntPtr player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.RadioEvent(cPlayer, playerType, announcementID, iconID, announcementType);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRadioEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public ConnectionAcceptanceFilterStatus EventClassConnectionRequestEvent(IntPtr eventClass, IntPtr request, ref IntPtr message)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IConnectionRequest connectionRequest = (request == IntPtr.Zero ? null : new ConnectionRequest(request));
                string originalMessage = Marshal.PtrToStringUni(message);
                string refusalMessage = originalMessage;

                ConnectionAcceptanceFilterStatus connectionResult = ConnectionAcceptanceFilterStatus.StatusAccepting;

                connectionResult = mEventClass.ConnectionRequestEvent(connectionRequest, ref refusalMessage);
                    
                if (!originalMessage.Equals(refusalMessage, StringComparison.InvariantCulture))
                {
                    message = Marshal.StringToHGlobalUni(refusalMessage);
                }

                return connectionResult;
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassConnectionRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPlayerPreJoinEvent(IntPtr eventClass, IntPtr request)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IConnectionRequest connectionRequest = (request == IntPtr.Zero ? null : new ConnectionRequest(request));

                mEventClass.PlayerPreJoinEvent(connectionRequest);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPlayerPreJoinEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPlayerJoinEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.PlayerJoinEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPlayerJoinEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPlayerLeaveEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.PlayerLeaveEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPlayerLeaveEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPlayerLoadedEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.PlayerLoadedEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPlayerLoadedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassNameChangeEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.NameChangeEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassNameChangeEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassLevelLoadedEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.LevelLoadedEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassLevelLoadedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }
 
        public void EventClassRemixEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.RemixEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRemixEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassRebalanceEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.RebalanceEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRebalanceEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassSwapEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.SwapEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassSwapEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassGameOverEvent(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.GameOverEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassGameOverEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassConsoleOutputEvent(IntPtr eventClass, string output)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.ConsoleOutputEvent(output);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassConsoleOutputEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassRenLogEvent(IntPtr eventClass, string output)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.RenLogEvent(output);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRenLogEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassDALogEvent(IntPtr eventClass, string header, string output)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.DALogEvent(header, output);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassDALogEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int EventClassCharacterPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBaseControllerClass controller = (baseController == IntPtr.Zero ? null : new BaseControllerClass(baseController));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                ISoldierGameObjDef soldierDef = (item == IntPtr.Zero ? null : new SoldierGameObjDef(item));

                return mEventClass.CharacterPurchaseRequestEvent(controller, cPlayer, ref cost, soldierDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassCharacterPurchaseRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int EventClassVehiclePurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBaseControllerClass controller = (baseController == IntPtr.Zero ? null : new BaseControllerClass(baseController));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IVehicleGameObjDef vehicleDef = (item == IntPtr.Zero ? null : new VehicleGameObjDef(item));

                return mEventClass.VehiclePurchaseRequestEvent(controller, cPlayer, ref cost, vehicleDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehiclePurchaseRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int EventClassPowerUpPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBaseControllerClass controller = (baseController == IntPtr.Zero ? null : new BaseControllerClass(baseController));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IPowerUpGameObjDef powerUpDef = (item == IntPtr.Zero ? null : new PowerUpGameObjDef(item));

                return mEventClass.PowerUpPurchaseRequestEvent(controller, cPlayer, ref cost, powerUpDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPowerUpPurchaseRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int EventClassCustomPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, uint id)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBaseControllerClass controller = (baseController == IntPtr.Zero ? null : new BaseControllerClass(baseController));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.CustomPurchaseRequestEvent(controller, cPlayer, ref cost, id);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassCustomPurchaseRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassCharacterPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                ISoldierGameObjDef soldierDef = (item == IntPtr.Zero ? null : new SoldierGameObjDef(item));

                mEventClass.CharacterPurchaseEvent(cPlayer, cost, soldierDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassCharacterPurchaseEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassVehiclePurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IVehicleGameObjDef vehicleDef = (item == IntPtr.Zero ? null : new VehicleGameObjDef(item));

                mEventClass.VehiclePurchaseEvent(cPlayer, cost, vehicleDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehiclePurchaseEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPowerUpPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IPowerUpGameObjDef powerUpDef = (item == IntPtr.Zero ? null : new PowerUpGameObjDef(item));

                mEventClass.PowerUpPurchaseEvent(cPlayer, cost, powerUpDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPowerUpPurchaseEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassCustomPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, uint id)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.CustomPurchaseEvent(cPlayer, cost, id);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassCustomPurchaseEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassRefillEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.RefillEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRefillEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassSuicideEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.SuicideEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassSuicideEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassTeamChangeRequestEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.TeamChangeRequestEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassTeamChangeRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassTeamChangeEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.TeamChangeEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassTeamChangeEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassVehicleEntryRequestEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, ref int seat)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mEventClass.VehicleEntryRequestEvent(vehicleObj, cPlayer, ref seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehicleEntryRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassVehicleEnterEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, int seat)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.VehicleEnterEvent(vehicleObj, cPlayer, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehicleEnterEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassVehicleExitEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, int seat)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));
                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.VehicleExitEvent(vehicleObj, cPlayer, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehicleExitEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassPowerUpGrantRequestEvent(IntPtr eventClass, IntPtr player, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IPowerUpGameObjDef powerUpDef = (powerUp== IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj puObj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                return mEventClass.PowerUpGrantRequestEvent(cPlayer, powerUpDef, puObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPowerUpGrantRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPowerUpGrantEvent(IntPtr eventClass, IntPtr player, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IPowerUpGameObjDef powerUpDef = (powerUp == IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj puObj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                mEventClass.PowerUpGrantEvent(cPlayer, powerUpDef, puObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPowerUpGrantEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassAddWeaponRequestEvent(IntPtr eventClass, IntPtr player, IntPtr weapon)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IWeaponDefinitionClass weaponDef = (weapon == IntPtr.Zero ? null : new WeaponDefinitionClass(weapon));

                return mEventClass.AddWeaponRequestEvent(cPlayer, weaponDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassAddWeaponRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassAddWeaponEvent(IntPtr eventClass, IntPtr player, IntPtr weapon)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IWeaponClass weaponClass = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mEventClass.AddWeaponEvent(cPlayer, weaponClass);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassAddWeaponEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassRemoveWeaponEvent(IntPtr eventClass, IntPtr player, IntPtr weapon)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IWeaponClass weaponClass = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mEventClass.RemoveWeaponEvent(cPlayer, weaponClass);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRemoveWeaponEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassClearWeaponsEvent(IntPtr eventClass, IntPtr player)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mEventClass.ClearWeaponsEvent(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassClearWeaponsEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassBeaconDeployEvent(IntPtr eventClass, IntPtr beacon)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBeaconGameObj beaconObj = (beacon == IntPtr.Zero ? null : new BeaconGameObj(beacon));

                mEventClass.BeaconDeployEvent(beaconObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassBeaconDeployEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassBeaconDetonateEvent(IntPtr eventClass, IntPtr beacon)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IBeaconGameObj beaconObj = (beacon == IntPtr.Zero ? null : new BeaconGameObj(beacon));

                mEventClass.BeaconDetonateEvent(beaconObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassBeaconDetonateEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassC4DetonateRequestEvent(IntPtr eventClass, IntPtr c4, IntPtr triggerer)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IC4GameObj c4Obj = (c4 == IntPtr.Zero ? null : new C4GameObj(c4));
                ISmartGameObj smartTriggerer = (triggerer == IntPtr.Zero ? null : new SmartGameObj(triggerer));

                return mEventClass.C4DetonateRequestEvent(c4Obj, smartTriggerer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassC4DetonateRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassC4DetonateEvent(IntPtr eventClass, IntPtr c4)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IC4GameObj c4Obj = (c4 == IntPtr.Zero ? null : new C4GameObj(c4));

                mEventClass.C4DetonateEvent(c4Obj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassC4DetonateEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassChangeCharacterEvent(IntPtr eventClass, IntPtr player, IntPtr soldier)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                ISoldierGameObjDef soldierDef = (soldier == IntPtr.Zero ? null : new SoldierGameObjDef(soldier));

                mEventClass.ChangeCharacterEvent(cPlayer, soldierDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassChangeCharacterEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassVehicleFlipEvent(IntPtr eventClass, IntPtr vehicle)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                return mEventClass.VehicleFlipEvent(vehicleObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassVehicleFlipEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassRequestVehicleEvent(IntPtr eventClass, IntPtr factory, IntPtr vehicle, IntPtr player, float delay)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IVehicleFactoryGameObj vehicleFactory = (factory == IntPtr.Zero ? null : new VehicleFactoryGameObj(factory));
                IVehicleGameObjDef vehicleObjDef = (vehicle == IntPtr.Zero ? null : new VehicleGameObjDef(vehicle));

                IcPlayer cPlayer;
                if (player == IntPtr.Zero)
                {
                    cPlayer = null;
                }
                else
                {
                    cPlayer = new cPlayer(player);
                }

                return mEventClass.RequestVehicleEvent(vehicleFactory, vehicleObjDef, cPlayer, delay);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassRequestVehicleEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassThink(IntPtr eventClass)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.Think();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassThink)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassObjectCreatedEvent(IntPtr eventClass, IntPtr obj)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));

                mEventClass.ObjectCreatedEvent(scriptableObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassObjectCreatedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassStockClientDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, float damage, uint warhead)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));
                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                return mEventClass.StockClientDamageRequestEvent(victimObj, damagerObj, damage, warhead);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassStockClientDamageRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassTTClientDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, IntPtr ammo, string bone)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));
                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));
                IAmmoDefinitionClass ammoDef = (ammo == IntPtr.Zero ? null : new AmmoDefinitionClass(ammo));

                return mEventClass.TTClientDamageRequestEvent(victimObj, damagerObj, ammoDef, bone);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassTTClientDamageRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool EventClassDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));
                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                return mEventClass.DamageRequestEvent(victimObj, damagerObj, ref damage, ref warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassDamageRequestEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassDamageEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));
                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                mEventClass.DamageEvent(victimObj, damagerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassDamageEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassKillEvent(IntPtr eventClass, IntPtr victim, IntPtr killer, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));
                IArmedGameObj killerObj = (killer == IntPtr.Zero ? null : new ArmedGameObj(killer));

                mEventClass.KillEvent(victimObj, killerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassKillEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassCustomEvent(IntPtr eventClass, IntPtr obj, int type, int param, IntPtr sender)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj senderObj = (sender == IntPtr.Zero ? null : new ScriptableGameObj(sender));

                mEventClass.CustomEvent(scriptableObj, type, param, senderObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassCustomEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassPokeEvent(IntPtr eventClass, IntPtr player, IntPtr obj)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));
                IPhysicalGameObj physicalObj = (obj == IntPtr.Zero ? null : new PhysicalGameObj(obj));

                mEventClass.PokeEvent(cPlayer, physicalObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassPokeEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassZoneEnterEvent(IntPtr eventClass, IntPtr obj, IntPtr enterer)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IScriptZoneGameObj zoneObj = (obj == IntPtr.Zero ? null : new ScriptZoneGameObj(obj));
                IPhysicalGameObj physicalEnterer = (enterer == IntPtr.Zero ? null : new PhysicalGameObj(enterer));

                mEventClass.ZoneEnterEvent(zoneObj, physicalEnterer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassZoneEnterEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassZoneExitEvent(IntPtr eventClass, IntPtr obj, IntPtr exiter)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IScriptZoneGameObj zoneObj = (obj == IntPtr.Zero ? null : new ScriptZoneGameObj(obj));
                IPhysicalGameObj physicalExiter = (exiter == IntPtr.Zero ? null : new PhysicalGameObj(exiter));

                mEventClass.ZoneExitEvent(zoneObj, physicalExiter);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassZoneExitEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassObjectDestroyedEvent(IntPtr eventClass, IntPtr obj)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));

                mEventClass.ObjectDestroyedEvent(scriptableObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassObjectDestroyedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void EventClassTimerExpired(IntPtr eventClass, int number, uint data)
        {
            try
            {
                IRenSharpEventClass mEventClass = DAEventManager.AsManagedEventClass(eventClass);
                if (mEventClass == null)
                {
                    throw new ArgumentException($"Argument '{nameof(eventClass)}' is not a managed event class.");
                }

                mEventClass.TimerExpired(number, data);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(EventClassTimerExpired)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverDestructed(IntPtr observer)
        {
            try
            {
                ScriptableGameObj.OnManagedObserverDestructed(observer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverDestroyed(IntPtr observer, IntPtr obj)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));

                mObserver.Destroyed(scriptableObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDestroyed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverCustom(IntPtr observer, IntPtr obj, int message, int param, IntPtr sender)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj senderObj = (sender == IntPtr.Zero ? null : new ScriptableGameObj(sender));

                mObserver.Custom(scriptableObj, message, param, senderObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverCustom)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverPoked(IntPtr observer, IntPtr obj, IntPtr poker)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj pokerObj = (poker == IntPtr.Zero ? null : new ScriptableGameObj(poker));

                mObserver.Poked(scriptableObj, pokerObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverPoked)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverEntered(IntPtr observer, IntPtr obj, IntPtr enterer)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj entererObj = (enterer == IntPtr.Zero ? null : new ScriptableGameObj(enterer));

                mObserver.Entered(scriptableObj, entererObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverEntered)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverExited(IntPtr observer, IntPtr obj, IntPtr exiter)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj exiterObj = (exiter == IntPtr.Zero ? null : new ScriptableGameObj(exiter));

                mObserver.Exited(scriptableObj, exiterObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverExited)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverSoundHeard(IntPtr observer, IntPtr obj, IntPtr sound)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                ICombatSound soundObj = (sound == IntPtr.Zero ? null : new CombatSound(sound));

                mObserver.SoundHeard(scriptableObj, soundObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverSoundHeard)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverEnemySeen(IntPtr observer, IntPtr obj, IntPtr enemy)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));
                IScriptableGameObj enemyObj = (enemy == IntPtr.Zero ? null : new ScriptableGameObj(enemy));

                mObserver.EnemySeen(scriptableObj, enemyObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverEnemySeen)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverActionComplete(IntPtr observer, IntPtr obj, int actionID, ActionCompleteReason completeReason)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));

                mObserver.ActionComplete(scriptableObj, actionID, completeReason);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverActionComplete)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverTimerExpired(IntPtr observer, IntPtr obj, int number)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.TimerExpired(number, null);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverTimerExpired)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverAnimationComplete(IntPtr observer, IntPtr obj, string name)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj scriptableObj = (obj == IntPtr.Zero ? null : new ScriptableGameObj(obj));

                mObserver.AnimationComplete(scriptableObj, name);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverAnimationComplete)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverInit(IntPtr observer)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Init(mObserver.Owner);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverVehicleEntryRequest1(IntPtr observer, IntPtr player, ref int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mObserver.VehicleEntryRequest(mObserver.Owner, cPlayer, ref seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleEntryRequest1)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverVehicleEntryRequest2(IntPtr observer, IntPtr vehicle, ref int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                return mObserver.VehicleEntryRequest(mObserver.Owner, vehicleObj, ref seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleEntryRequest2)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverVehicleEnter1(IntPtr observer, IntPtr player, int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mObserver.VehicleEnter(mObserver.Owner, cPlayer, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleEnter1)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverVehicleEnter2(IntPtr observer, IntPtr vehicle, int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                mObserver.VehicleEnter(mObserver.Owner, vehicleObj, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleEnter2)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverVehicleExit1(IntPtr observer, IntPtr player, int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mObserver.VehicleExit(mObserver.Owner, cPlayer, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleExit1)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverVehicleExit2(IntPtr observer, IntPtr vehicle, int seat)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                mObserver.VehicleExit(mObserver.Owner, vehicleObj, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleExit2)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverVehicleFlip(IntPtr observer)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                return mObserver.VehicleFlip(mObserver.Owner);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverVehicleFlip)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverDamageDealtRequest(IntPtr observer, IntPtr victim, ref float damage, ref uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                return mObserver.DamageDealtRequest(mObserver.Owner, victimObj, ref damage, ref warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDamageDealtRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverDamageReceivedRequest(IntPtr observer, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                return mObserver.DamageReceivedRequest(mObserver.Owner, damagerObj, ref damage, ref warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDamageReceivedRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverDamageDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                mObserver.DamageDealt(mObserver.Owner, victimObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDamageDealt)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverDamageReceived(IntPtr observer, IntPtr damager, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                mObserver.DamageReceived(mObserver.Owner, damagerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverDamageReceived)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverKillDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                mObserver.KillDealt(mObserver.Owner, victimObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverKillDealt)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverKillReceived(IntPtr observer, IntPtr killer, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj killerObj = (killer == IntPtr.Zero ? null : new ArmedGameObj(killer));

                mObserver.KillReceived(mObserver.Owner, killerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverKillReceived)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverPowerUpGrantRequest1(IntPtr observer, IntPtr player)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mObserver.PowerUpGrantRequest(mObserver.Owner, cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverPowerUpGrantRequest1)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverPowerUpGrantRequest2(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef powerUpDef = (powerUp == IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj powerObj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                return mObserver.PowerUpGrantRequest(mObserver.Owner, powerUpDef, powerObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverPowerUpGrantRequest2)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverPowerUpGrant1(IntPtr observer, IntPtr player)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mObserver.PowerUpGrant(mObserver.Owner, cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverPowerUpGrant1)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverPowerUpGrant2(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef powerUpDef = (powerUp == IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj powerObj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                mObserver.PowerUpGrant(mObserver.Owner, powerUpDef, powerObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverPowerUpGrant2)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool ObserverAddWeaponRequest(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponDefinitionClass weaponDef = (weapon == IntPtr.Zero ? null : new WeaponDefinitionClass(weapon));

                return mObserver.AddWeaponRequest(mObserver.Owner, weaponDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverAddWeaponRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverAddWeapon(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponClass weaponObj = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mObserver.AddWeapon(mObserver.Owner, weaponObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverAddWeapon)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverRemoveWeapon(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponClass weaponObj = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mObserver.RemoveWeapon(mObserver.Owner, weaponObj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverRemoveWeapon)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ObserverClearWeapons(IntPtr observer)
        {
            try
            {
                IRenSharpGameObjObserverClass mObserver = ScriptableGameObj.AsManagedObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.ClearWeapons(mObserver.Owner);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ObserverClearWeapons)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverDestructed(IntPtr observer)
        {
            try
            {
                DAPlayerClass.OnManagedPlayerObserverDestructed(observer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverInit(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Init();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverJoin(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Join();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverJoin)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverLeave(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Leave();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverLeave)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverLevelLoaded(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.LevelLoaded();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverLevelLoaded)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverPlayerLoaded(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.PlayerLoaded();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPlayerLoaded)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverNameChange(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.NameChange();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverNameChange)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverTeamChange(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.TeamChange();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverTeamChange)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int PlayerObserverCharacterPurchaseRequest(IntPtr observer, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                ISoldierGameObjDef itemDef = (item == IntPtr.Zero ? null : new SoldierGameObjDef(item));

                return mObserver.CharacterPurchaseRequest(ref cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCharacterPurchaseRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int PlayerObserverVehiclePurchaseRequest(IntPtr observer, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObjDef itemDef = (item == IntPtr.Zero ? null : new VehicleGameObjDef(item));

                return mObserver.VehiclePurchaseRequest(ref cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverVehiclePurchaseRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int PlayerObserverPowerUpPurchaseRequest(IntPtr observer, ref float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef itemDef = (item == IntPtr.Zero ? null : new PowerUpGameObjDef(item));

                return mObserver.PowerUpPurchaseRequest(ref cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPowerUpPurchaseRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public int PlayerObserverCustomPurchaseRequest(IntPtr observer, ref float cost, uint id)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                return mObserver.CustomPurchaseRequest(ref cost, id);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCustomPurchaseRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverCharacterPurchase(IntPtr observer, float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                ISoldierGameObjDef itemDef = (item == IntPtr.Zero ? null : new SoldierGameObjDef(item));

                mObserver.CharacterPurchase(cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCharacterPurchase)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverVehiclePurchase(IntPtr observer, float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObjDef itemDef = (item == IntPtr.Zero ? null : new VehicleGameObjDef(item));

                mObserver.VehiclePurchase(cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverVehiclePurchase)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverPowerUpPurchase(IntPtr observer, float cost, IntPtr item)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef itemDef = (item == IntPtr.Zero ? null : new PowerUpGameObjDef(item));

                mObserver.PowerUpPurchase(cost, itemDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPowerUpPurchase)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverCustomPurchase(IntPtr observer, float cost, uint id)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.CustomPurchase(cost, id);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCustomPurchase)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverVehicleEntryRequest(IntPtr observer, IntPtr vehicle, ref int seat)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                return mObserver.VehicleEntryRequest(vehicleObj, ref seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverVehicleEntryRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverVehicleEnter(IntPtr observer, IntPtr vehicle, int seat)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                mObserver.VehicleEnter(vehicleObj, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverVehicleEnter)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverVehicleExit(IntPtr observer, IntPtr vehicle, int seat)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IVehicleGameObj vehicleObj = (vehicle == IntPtr.Zero ? null : new VehicleGameObj(vehicle));

                mObserver.VehicleExit(vehicleObj, seat);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverVehicleExit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverPowerUpGrantRequest(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef powerUpDef = (powerUp == IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj obj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                return mObserver.PowerUpGrantRequest(powerUpDef, obj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPowerUpGrantRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverPowerUpGrant(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IPowerUpGameObjDef powerUpDef = (powerUp == IntPtr.Zero ? null : new PowerUpGameObjDef(powerUp));
                IPowerUpGameObj obj = (powerUpObj == IntPtr.Zero ? null : new PowerUpGameObj(powerUpObj));

                mObserver.PowerUpGrant(powerUpDef, obj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPowerUpGrant)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverAddWeaponRequest(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponDefinitionClass weaponDef = (weapon == IntPtr.Zero ? null : new WeaponDefinitionClass(weapon));

                return mObserver.AddWeaponRequest(weaponDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverAddWeaponRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverAddWeapon(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponClass weaponClass = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mObserver.AddWeapon(weaponClass);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverAddWeapon)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverRemoveWeapon(IntPtr observer, IntPtr weapon)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IWeaponClass weaponClass = (weapon == IntPtr.Zero ? null : new WeaponClass(weapon));

                mObserver.RemoveWeapon(weaponClass);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverRemoveWeapon)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverClearWeapons(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.ClearWeapons();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverClearWeapons)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverC4DetonateRequest(IntPtr observer, IntPtr c4)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IC4GameObj c4Obj = (c4 == IntPtr.Zero ? null : new C4GameObj(c4));

                return mObserver.C4DetonateRequest(c4Obj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverC4DetonateRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverC4Detonate(IntPtr observer, IntPtr c4)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IC4GameObj c4Obj = (c4 == IntPtr.Zero ? null : new C4GameObj(c4));

                mObserver.C4Detonate(c4Obj);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverC4Detonate)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverChangeCharacter(IntPtr observer, IntPtr soldier)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                ISoldierGameObjDef soldierDef = (soldier == IntPtr.Zero ? null : new SoldierGameObjDef(soldier));

                mObserver.ChangeCharacter(soldierDef);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverChangeCharacter)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverCreated(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Created();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCreated)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverDestroyed(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Destroyed();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDestroyed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverDamageDealtRequest(IntPtr observer, IntPtr victim, ref float damage, ref uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                return mObserver.DamageDealtRequest(victimObj, ref damage, ref warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDamageDealtRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool PlayerObserverDamageReceivedRequest(IntPtr observer, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                return mObserver.DamageReceivedRequest(damagerObj, ref damage, ref warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDamageReceivedRequest)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverDamageDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                mObserver.DamageDealt(victimObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDamageDealt)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverDamageReceived(IntPtr observer, IntPtr damager, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj damagerObj = (damager == IntPtr.Zero ? null : new ArmedGameObj(damager));

                mObserver.DamageReceived(damagerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverDamageReceived)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverKillDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IDamageableGameObj victimObj = (victim == IntPtr.Zero ? null : new DamageableGameObj(victim));

                mObserver.KillDealt(victimObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverKillDealt)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverKillReceived(IntPtr observer, IntPtr killer, float damage, uint warhead, float scale, DADamageType type)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IArmedGameObj killerObj = (killer == IntPtr.Zero ? null : new ArmedGameObj(killer));

                mObserver.KillReceived(killerObj, damage, warhead, scale, type);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverKillReceived)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverCustom(IntPtr observer, IntPtr sender, int type, int param)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IScriptableGameObj senderObj = (sender == IntPtr.Zero ? null : new ScriptableGameObj(sender));

                mObserver.Custom(senderObj, type, param);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverCustom)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverPoked(IntPtr observer, IntPtr player)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                IcPlayer cPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mObserver.Poked(cPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverPoked)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverTimerExpired(IntPtr observer, int number, uint data)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.TimerExpired(number, data);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverTimerExpired)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerObserverThink(IntPtr observer)
        {
            try
            {
                IRenSharpPlayerObserverClass mObserver = DAPlayerClass.AsManagedPlayerObserver(observer);
                if (mObserver == null)
                {
                    throw new ArgumentException($"Argument '{nameof(observer)}' is not a managed observer.");
                }

                mObserver.Think();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerObserverThink)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ConsoleFunctionDestructed(IntPtr function)
        {
            try
            {
                Engine.OnManagedConsoleFunctionDestructed(function);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ConsoleFunctionDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void ConsoleFunctionActivate(IntPtr function, string pArgs)
        {
            try
            {
                IRenSharpConsoleFunctionClass mFunction = Engine.AsManagedConsoleFunction(function);
                if (mFunction == null)
                {
                    throw new ArgumentException($"Argument '{nameof(function)}' is not a managed console function.");
                }

                mFunction.Activate(pArgs);

                using (IUnmanagedContainer<IDATokenClass> tokenArgs = DATokenClass.CreateDATokenClass(pArgs, 0))
                {
                    mFunction.Activate(tokenArgs.UnmanagedObject);
                }
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(ConsoleFunctionActivate)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameFeatureFactoryDestructed(IntPtr factory)
        {
            try
            {
                DAGameManager.OnManagedGameFeatureFactoryDestructed(factory);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameFeatureFactoryDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public IntPtr GameFeatureFactoryCreateInstance(IntPtr factory)
        {
            try
            {
                IRenSharpGameFeatureFactoryClass mFactory = DAGameManager.AsManagedGameFeatureFactory(factory);
                if (mFactory == null)
                {
                    throw new ArgumentException($"Argument '{nameof(factory)}' is not a managed game feature factory.");
                }

                var instance = mFactory.CreateInstance();

                return instance.DAGameFeatureClassPointer;
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameFeatureFactoryCreateInstance)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameFeatureDestructed(IntPtr gameFeature)
        {
            try
            {
                DAGameManager.OnManagedGameFeatureDestructed(gameFeature);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameFeatureDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameFeatureInit(IntPtr gameFeature)
        {
            try
            {
                IRenSharpGameFeatureClass mGameFeature = DAGameManager.AsManagedGameFeature(gameFeature);
                if (mGameFeature == null)
                {
                    throw new ArgumentException($"Argument '{nameof(gameFeature)}' is not a managed game feature.");
                }

                mGameFeature.Init();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameFeatureInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerDataFactoryDestructed(IntPtr playerDataFactory)
        {
            try
            {
                DAPlayerManager.OnManagedPlayerDataFactoryDestructed(playerDataFactory);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataFactoryDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public IntPtr PlayerDataFactoryCreateData(IntPtr playerDataFactory)
        {
            try
            {
                IRenSharpPlayerDataFactoryClass mFactory = DAPlayerManager.AsManagedPlayerDataFactory(playerDataFactory);
                if (mFactory == null)
                {
                    throw new ArgumentException($"Argument '{nameof(playerDataFactory)}' is not a managed player data factory.");
                }

                using (var managedPlayerData = mFactory.CreateData())
                {
                    if (managedPlayerData == null)
                    {
                        return IntPtr.Zero;
                    }

                    var unmanagedPlayerData = managedPlayerData.UnmanagedObject;
                    managedPlayerData.ReleaseObject(); // At this point the unmanaged side is in charge of this object's lifetime

                    return unmanagedPlayerData.DAPlayerDataClassPointer;
                }
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataFactoryCreateData)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerDataDestructed(IntPtr playerData)
        {
            try
            {
                DAPlayerManager.OnManagedPlayerDataDestructed(playerData);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerDataInit(IntPtr playerData)
        {
            try
            {
                IRenSharpPlayerDataClass mPlayerData = DAPlayerManager.AsManagedPlayerData(playerData);
                if (mPlayerData == null)
                {
                    throw new ArgumentException($"Argument '{nameof(playerData)}' is not a managed player data.");
                }

                mPlayerData.Init();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerDataClearLevel(IntPtr playerData)
        {
            try
            {
                IRenSharpPlayerDataClass mPlayerData = DAPlayerManager.AsManagedPlayerData(playerData);
                if (mPlayerData == null)
                {
                    throw new ArgumentException($"Argument '{nameof(playerData)}' is not a managed player data.");
                }

                mPlayerData.ClearLevel();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataClearLevel)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void PlayerDataClearSession(IntPtr playerData)
        {
            try
            {
                IRenSharpPlayerDataClass mPlayerData = DAPlayerManager.AsManagedPlayerData(playerData);
                if (mPlayerData == null)
                {
                    throw new ArgumentException($"Argument '{nameof(playerData)}' is not a managed player data.");
                }

                mPlayerData.ClearSession();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(PlayerDataClearSession)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameModeFactoryDestructed(IntPtr factory)
        {
            try
            {
                DAGameManager.OnManagedGameModeFactoryDestructed(factory);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameModeFactoryDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public IntPtr GameModeFactoryCreateInstance(IntPtr factory)
        {
            try
            {
                IRenSharpGameModeFactoryClass mFactory = DAGameManager.AsManagedGameModeFactory(factory);
                if (mFactory == null)
                {
                    throw new ArgumentException($"Argument '{nameof(factory)}' is not a managed game mode factory.");
                }

                var instance = mFactory.CreateInstance();

                return instance.DAGameModeClassPointer;
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameModeFactoryCreateInstance)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameModeDestructed(IntPtr gameMode)
        {
            try
            {
                DAGameManager.OnManagedGameModeDestructed(gameMode);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameModeDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void GameModeInit(IntPtr gameMode)
        {
            try
            {
                IRenSharpGameModeClass mGameMode = DAGameManager.AsManagedGameMode(gameMode);
                if (mGameMode == null)
                {
                    throw new ArgumentException($"Argument '{nameof(gameMode)}' is not a managed game mode.");
                }

                mGameMode.Init();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(GameModeInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateModifierFactoryDestructed(IntPtr factory)
        {
            try
            {
                DACrateManager.OnManagedCrateModifierFactoryDestructed(factory);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateModifierFactoryDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public IntPtr CrateModifierFactoryCreate(IntPtr factory, string parameters)
        {
            try
            {
                IRenSharpCrateModifierFactoryClass mFactory = DACrateManager.AsManagedCrateModifierFactory(factory);
                if (mFactory == null)
                {
                    throw new ArgumentException($"Argument '{nameof(factory)}' is not a managed crate modifier factory.");
                }

                using (var managedCrateModifierFactory = mFactory.Create(parameters))
                {
                    if (managedCrateModifierFactory == null)
                    {
                        return IntPtr.Zero;
                    }

                    var unmanagedCrateModifierFactory = managedCrateModifierFactory.UnmanagedObject;
                    managedCrateModifierFactory.ReleaseObject(); // At this point the unmanaged side is in charge of this object's lifetime

                    return unmanagedCrateModifierFactory.DACrateModifierClassPointer;
                }
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateModifierFactoryCreate)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateModifierDestructed(IntPtr crateModifier)
        {
            try
            {
                DACrateManager.OnManagedCrateModifierDestructed(crateModifier);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateModifierDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateModifierInit(IntPtr crateModifier, string parameters)
        {
            try
            {
                IRenSharpCrateModifierClass mCrateModifier = DACrateManager.AsManagedCrateModifier(crateModifier);
                if (mCrateModifier == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crateModifier)}' is not a managed crate modifier.");
                }

                using (var tokenParser = DATokenParserClass.CreateDATokenParserClass(parameters, '|'))
                {
                    string operatorValueStr = tokenParser.UnmanagedObject.GetString();
                    if (operatorValueStr == null)
                    {
                        operatorValueStr = string.Empty;
                    }

                    mCrateModifier.Init(operatorValueStr);

                    using (var tokens = DATokenClass.CreateDATokenClass(tokenParser.UnmanagedObject))
                    {
                        mCrateModifier.Init(tokens.UnmanagedObject);
                    }
                }
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateModifierInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateModifierCalculateOdds(IntPtr crateModifier, ref float odds, IntPtr player)
        {
            try
            {
                IRenSharpCrateModifierClass mCrateModifier = DACrateManager.AsManagedCrateModifier(crateModifier);
                if (mCrateModifier == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crateModifier)}' is not a managed crate modifier.");
                }

                IcPlayer mPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mCrateModifier.CalculateOdds(ref odds, mPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateModifierCalculateOdds)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateDestructed(IntPtr crate)
        {
            try
            {
                DACrateManager.OnManagedCrateDestructed(crate);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateInit(IntPtr crate)
        {
            try
            {
                IRenSharpCrateClass mCrate = DACrateManager.AsManagedCrate(crate);
                if (mCrate == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crate)}' is not a managed crate.");
                }

                mCrate.Init();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateSettingsLoaded(IntPtr crate)
        {
            try
            {
                IRenSharpCrateClass mCrate = DACrateManager.AsManagedCrate(crate);
                if (mCrate == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crate)}' is not a managed crate.");
                }

                mCrate.SettingsLoaded();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateSettingsLoaded)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateCalculateOdds(IntPtr crate, IntPtr player)
        {
            try
            {
                IRenSharpCrateClass mCrate = DACrateManager.AsManagedCrate(crate);
                if (mCrate == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crate)}' is not a managed crate.");
                }

                IcPlayer mPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mCrate.CalculateOdds(mPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateCalculateOdds)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public bool CrateCanActivate(IntPtr crate, IntPtr player)
        {
            try
            {
                IRenSharpCrateClass mCrate = DACrateManager.AsManagedCrate(crate);
                if (mCrate == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crate)}' is not a managed crate.");
                }

                IcPlayer mPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                return mCrate.CanActivate(mPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateCanActivate)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateActivate(IntPtr crate, IntPtr player)
        {
            try
            {
                IRenSharpCrateClass mCrate = DACrateManager.AsManagedCrate(crate);
                if (mCrate == null)
                {
                    throw new ArgumentException($"Argument '{nameof(crate)}' is not a managed crate.");
                }

                IcPlayer mPlayer = (player == IntPtr.Zero ? null : new cPlayer(player));

                mCrate.Activate(mPlayer);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateActivate)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void CrateFactoryDestructed(IntPtr factory)
        {
            try
            {
                DACrateManager.OnManagedCrateFactoryDestructed(factory);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateFactoryDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public IntPtr CrateFactoryCreateInstance(IntPtr factory)
        {
            try
            {
                IRenSharpCrateFactoryClass mFactory = DACrateManager.AsManagedCrateFactory(factory);
                if (mFactory == null)
                {
                    throw new ArgumentException($"Argument '{nameof(factory)}' is not a managed crate factory.");
                }

                var instance = mFactory.CreateInstance();

                return instance.DACrateClassPointer;
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(CrateFactoryCreateInstance)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void NodeDestructed(IntPtr node)
        {
            try
            {
                DANodeManagerClass.OnManagedNodeDestructed(node);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(NodeDestructed)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void NodeInit(IntPtr node, IntPtr ini, string header)
        {
            try
            {
                IRenSharpNodeClass mNode = DANodeManagerClass.AsManagedNode(node);
                if (mNode == null)
                {
                    throw new ArgumentException($"Argument '{nameof(node)}' is not a managed node.");
                }

                IINIClass mINI = (ini == IntPtr.Zero ? null : new INIClass(ini));

                mNode.Init(mINI, header);
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(NodeInit)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void NodeContestedEvent(IntPtr node)
        {
            try
            {
                IRenSharpNodeClass mNode = DANodeManagerClass.AsManagedNode(node);
                if (mNode == null)
                {
                    throw new ArgumentException($"Argument '{nameof(node)}' is not a managed node.");
                }

                mNode.ContestedEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(NodeContestedEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        public void NodeCaptureEvent(IntPtr node)
        {
            try
            {
                IRenSharpNodeClass mNode = DANodeManagerClass.AsManagedNode(node);
                if (mNode == null)
                {
                    throw new ArgumentException($"Argument '{nameof(node)}' is not a managed node.");
                }

                mNode.CaptureEvent();
            }
            catch (Exception ex)
            {
                FatalRenSharpException exception = new FatalRenSharpException($"{nameof(RenSharpAppDomainManager)}.{nameof(NodeCaptureEvent)} failed fatally", ex);

                Imports.OnFatalException(exception.ToString());

                throw exception;
            }
        }

        private void LoadPlugin(string pluginPath)
        {
            Engine.ConsoleOutput($"| - Plugin '{pluginPath}' start\n");

            Assembly pluginAssembly = null;
            try
            {
                pluginAssembly = Assembly.LoadFrom(pluginPath);
            }
            catch (Exception ex)
            {
                if (
                    ex is FileNotFoundException ||
                    ex is FileLoadException ||
                    ex is BadImageFormatException ||
                    ex is SecurityException ||
                    ex is ArgumentException ||
                    ex is PathTooLongException)
                {
                    Engine.ConsoleOutput($"|\tFailed to load assembly ({ex.GetType().Name}):\n");
                    Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                }
                else
                {
                    throw ex;
                }
            }

            if (pluginAssembly != null)
            {
                Type[] exportedTypes = null;
                try
                {
                    exportedTypes = pluginAssembly.GetExportedTypes();
                }
                catch (Exception ex)
                {
                    if (
                        ex is NotSupportedException ||
                        ex is FileNotFoundException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to get exported types ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else
                    {
                        throw ex;
                    }
                }

                if (exportedTypes != null)
                {
                    foreach (Type type in exportedTypes)
                    {
                        if (Attribute.GetCustomAttribute(type, typeof(RenSharpIgnoreAttribute)) == null)
                        {
                            TryLoadEventClass(type);
                            TryLoadConsoleFunction(type);
                            TryLoadChatCommandClass(type);
                            TryLoadKeyHookClass(type);
                            TryLoadGameFeatureFactoryClass(type);
                            TryLoadPlayerDataFactoryClass(type);
                            TryLoadGameModeFactoryClass(type);
                            TryLoadCrateModifierFactoryClass(type);
                            TryLoadCrateFactoryClass(type);
                        }
                    }  
                }
            }

            Engine.ConsoleOutput($"| - Plugin '{pluginPath}' end\n");
        }

        private void TryLoadEventClass(Type type)
        {
            if (typeof(RenSharpEventClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                RenSharpEventClass eventClass = null;
                try
                {
                    eventClass = (RenSharpEventClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create event handler {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create event handler {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (eventClass != null)
                {
                    eventClass.AttachToUnmanagedObject();
                    eventClass.RegisterManagedObject();

                    Engine.ConsoleOutput($"|\tAdded event handler {type.FullName}\n");
                }
            }
        }

        private void TryLoadConsoleFunction(Type type)
        {
            if (typeof(RenSharpConsoleFunctionClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                RenSharpConsoleFunctionClass consoleFunction = null;
                try
                {
                    consoleFunction = (RenSharpConsoleFunctionClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create console function {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create console function {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (consoleFunction != null)
                {
                    Engine.AddConsoleFunction(consoleFunction);

                    Engine.ConsoleOutput($"|\tAdded console function {type.FullName}\n");
                }
            }
        }

        private void TryLoadChatCommandClass(Type type)
        {
            if (typeof(RenSharpChatCommandClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                RenSharpChatCommandClass chatCommand = null;
                try
                {
                    chatCommand = (RenSharpChatCommandClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create chat command {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create chat command {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (chatCommand != null)
                {
                    chatCommand.RegisterManagedObject();

                    Engine.ConsoleOutput($"|\tAdded chat command {type.FullName}\n");
                }
            }
        }

        private void TryLoadKeyHookClass(Type type)
        {
            if (typeof(RenSharpKeyHookClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                RenSharpKeyHookClass keyHook = null;
                try
                {
                    keyHook = (RenSharpKeyHookClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create key hook {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create key hook {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (keyHook != null)
                {
                    keyHook.RegisterManagedObject();

                    Engine.ConsoleOutput($"|\tAdded key hook {type.FullName}\n");
                }
            }
        }

        private void TryLoadGameFeatureFactoryClass(Type type)
        {
            if (typeof(IRenSharpGameFeatureFactoryClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                IRenSharpGameFeatureFactoryClass gameFeatureFactory = null;
                try
                {
                    gameFeatureFactory = (IRenSharpGameFeatureFactoryClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create game feature factory {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create game feature factory {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (gameFeatureFactory != null)
                {
                    DAGameManager.AddGameFeature(gameFeatureFactory);

                    Engine.ConsoleOutput($"|\tAdded game feature factory {type.FullName}\n");
                }
            }
        }

        private void TryLoadPlayerDataFactoryClass(Type type)
        {
            if (
                typeof(IRenSharpPlayerDataFactoryClass).IsAssignableFrom(type) && 
                !typeof(IRenSharpGameFeatureEventClassPlayerDataFactory).IsAssignableFrom(type) &&
                !typeof(IRenSharpGameModeEventClassPlayerDataFactory).IsAssignableFrom(type) &&
                !type.IsAbstract && 
                !type.IsGenericType && 
                type.GetConstructor(Type.EmptyTypes) != null)
            {
                IRenSharpPlayerDataFactoryClass playerDataFactory = null;
                try
                {
                    playerDataFactory = (IRenSharpPlayerDataFactoryClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create player data factory {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create player data factory {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (playerDataFactory != null)
                {
                    DAPlayerManager.AddDataFactory(playerDataFactory);

                    Engine.ConsoleOutput($"|\tAdded player data factory {type.FullName}\n");
                }
            }
        }

        private void TryLoadGameModeFactoryClass(Type type)
        {
            if (typeof(IRenSharpGameModeFactoryClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                IRenSharpGameModeFactoryClass gameModeFactory = null;
                try
                {
                    gameModeFactory = (IRenSharpGameModeFactoryClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create game mode factory {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create game mode factory {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (gameModeFactory != null)
                {
                    DAGameManager.AddGameMode(gameModeFactory);

                    Engine.ConsoleOutput($"|\tAdded game mode factory {type.FullName}\n");
                }
            }
        }

        private void TryLoadCrateModifierFactoryClass(Type type)
        {
            if (typeof(IRenSharpCrateModifierFactoryClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                IRenSharpCrateModifierFactoryClass crateModifierFactory = null;
                try
                {
                    crateModifierFactory = (IRenSharpCrateModifierFactoryClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create crate modifier factory {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create create modifier factory {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (crateModifierFactory != null)
                {
                    DACrateManager.AddCrateModifier(crateModifierFactory);

                    Engine.ConsoleOutput($"|\tAdded crate modifier factory {type.FullName}\n");
                }
            }
        }

        private void TryLoadCrateFactoryClass(Type type)
        {
            if (typeof(IRenSharpCrateFactoryClass).IsAssignableFrom(type) && !type.IsAbstract && !type.IsGenericType && type.GetConstructor(Type.EmptyTypes) != null)
            {
                IRenSharpCrateFactoryClass crateFactory = null;
                try
                {
                    crateFactory = (IRenSharpCrateFactoryClass)Activator.CreateInstance(type);
                }
                catch (Exception ex)
                {
                    if (
                        ex is ArgumentException ||
                        ex is NotSupportedException ||
                        ex is MethodAccessException ||
                        ex is MemberAccessException ||
                        ex is InvalidComObjectException ||
                        ex is MissingMethodException ||
                        ex is COMException ||
                        ex is TypeLoadException)
                    {
                        Engine.ConsoleOutput($"|\tFailed to create crate factory {type.FullName} ({ex.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {ex.Message}\n");
                    }
                    else if (ex is TargetInvocationException targetException)
                    {
                        Exception innerException = targetException.InnerException;

                        Engine.ConsoleOutput($"|\tFailed to create create factory {type.FullName} ({innerException.GetType().Name}):\n");
                        Engine.ConsoleOutput($"|\t  {innerException.Message}\n");
                    }
                    else
                    {
                        throw;
                    }
                }

                if (crateFactory != null)
                {
                    DACrateManager.AddCrate(crateFactory);

                    Engine.ConsoleOutput($"|\tAdded crate factory {type.FullName}\n");
                }
            }
        }
    }
}
