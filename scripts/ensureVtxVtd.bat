@ECHO OFF

:: First of all, do these first!!!

:: Disable Windows Security Core Isolation
:: Disable Hyper-V
:: Disable Virtual Machine Platform & Hypervisor Platform
:: Registry Editor and Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\DeviceGuard, set to 0

:: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\DeviceGuard\Scenarios\HypervisorEnforcedCodeIntegrity = 0
:: HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\DeviceGuard\EnableVirtualizationBasedSecurity = 0 
:: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\DeviceGuard\RequirePlatformSecurityFeatures = 0

:: https://learn.microsoft.com/en-us/windows/security/identity-protection/credential-guard/configure?tabs=reg#disable-credential-guard

:: Run these in Admin PS
cd dgreadiness_v3.6
.\DG_Readiness_Tool_v3.6.ps1 -Disable

:: Run these commands line by line
bcdedit /set {0cb3b571-2f2e-4343-a879-d86a476d7215} loadoptions DISABLE-LSA-ISO,DISABLE-VBS
bcdedit /set vsmlaunchtype off
bcdedit /set hypervisorlaunchtype off
