#pragma once
#include "includes.h"
namespace pt
{	// 0x00400000+0x195404
}	
namespace offsets
{	//every four bytes from localplayer is each player
	DWORD armour = 0xD0;
	DWORD health = 0xEC;
	DWORD movekey = 0x80;
	DWORD movekeyalt = 0x74;
	DWORD posy = 0x28;
	DWORD posx = 0x2C;
	DWORD posz = 0x30;
	DWORD hozviewangle = 0x34;
	DWORD vertviewangle = 0x38;
	DWORD rollviewangle = 0x3C;
	DWORD headtogroundlevel = 0xC;
	DWORD SHOOT = 0x204;
	DWORD playername = 0x205;
	DWORD rshootspeed = 0x164; //rifle shoot speed offset
	DWORD RifleAmmoactive = 0x140;
	DWORD RifleAmmoreserve = 0x11C;
}
namespace addr
{
	DWORD ammo = 0x00195404;
	//baseModule + 0x18AC0C = player count
}