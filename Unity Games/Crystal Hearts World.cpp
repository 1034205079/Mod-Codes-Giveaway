//Game: Crystal Hearts World
//Version: 1.13
//APK: https://apkpure.com/crystal-hearts-world/com.baplay.chsea

public class PlayerController : MonoBehaviour
{
	public long MyReportID; // 0x160
	public bool get_CanUseSkill(); // Offset: 0x73DAE8
	public bool get_IsFrozen(); // Offset: 0x747F1C
	public int get_AttackPoint(); // Offset: 0x7424D0
}

public class UserDataManagerNetwork : UserDataManager
{
	private string get_osString(); // RVA: 0x9E1144 Offset: 0x9E1144
}

------------------------------------

int main()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r3
  int v5; // r0

  while ( !dword_6218 )
  {
    dword_6218 = sub_1348("/data/app/com.baplay.chsea-1/lib/arm/libil2cpp.so");
    if ( dword_6218
      || (dword_6218 = sub_1348("/data/app/com.baplay.chsea-2/lib/arm/libil2cpp.so")) != 0
      || (dword_6218 = sub_1348("/data/app-lib/com.baplay.chsea-1/libil2cpp.so")) != 0
      || (dword_6218 = sub_1348("/data/app-lib/com.baplay.chsea-2/libil2cpp.so")) != 0
      || (dword_6218 = sub_1348("libil2cpp.so")) != 0 )
    {
      MSHookFunction(getRealOffset(0x747F1C), sub_12C8, &dword_6228);
      MSHookFunction(getRealOffset(0x73DAE8), sub_12E4, &dword_621C);
      MSHookFunction(getRealOffset(0x7424D0), sub_1300, &dword_6224);
      v3 = dword_6218;
      if ( !dword_6218 )
      {
        v5 = sub_1348("/data/app/com.baplay.chsea-1/lib/arm/libil2cpp.so");
        dword_6218 = v5;
        if ( v5
          || (v5 = sub_1348("/data/app/com.baplay.chsea-2/lib/arm/libil2cpp.so"), (dword_6218 = v5) != 0)
          || (v5 = sub_1348("/data/app-lib/com.baplay.chsea-1/libil2cpp.so"), (dword_6218 = v5) != 0)
          || (v5 = sub_1348("/data/app-lib/com.baplay.chsea-2/libil2cpp.so"), (dword_6218 = v5) != 0) )
        {
          v3 = v5;
        }
        else
        {
          v3 = sub_1348("libil2cpp.so");
          dword_6218 = v3;
        }
      }
      MSHookFunction(v3 + 0x9E1144, (char *)&loc_12C4 + 1, &unk_622C);
      pthread_exit(0);
    }
    sleep(1);
  }
  return 0;
}

int __fastcall sub_12C8(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 352) < 0 )
    result = 1;
  else
    result = dword_6228();
  return result;
}

int __fastcall sub_12E4(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 352) < 0 )
    result = 0;
  else
    result = dword_621C();
  return result;
}

int __fastcall sub_1300(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 352) < 0 )
    result = 0;
  else
    result = 100 * dword_6224();
  return result;
}

int getRealOffset(int a1)
{
  int v1; // r5
  int v3; // r0

  v1 = a1;
  if ( dword_6218 )
    return dword_6218 + a1;
  v3 = sub_1348("/data/app/com.baplay.chsea-1/lib/arm/libil2cpp.so");
  dword_6218 = v3;
  if ( v3 )
    return v3 + v1;
  v3 = sub_1348("/data/app/com.baplay.chsea-2/lib/arm/libil2cpp.so");
  dword_6218 = v3;
  if ( v3 )
    return v3 + v1;
  v3 = sub_1348("/data/app-lib/com.baplay.chsea-1/libil2cpp.so");
  dword_6218 = v3;
  if ( v3 )
    return v3 + v1;
  v3 = sub_1348("/data/app-lib/com.baplay.chsea-2/libil2cpp.so");
  dword_6218 = v3;
  if ( v3 )
    return v3 + v1;
  dword_6218 = sub_1348("libil2cpp.so");
  return dword_6218 + v1;
}