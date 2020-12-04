#include "Sound.h"

Soundhead::Soundhead()
{
	sharingansoundbuffer.loadFromFile("Sound/Mangekyo_sound.ogg");
	sharinganeffect.setBuffer(sharingansoundbuffer);

	Teleportsoundbuffer.loadFromFile("Sound/Crow_sound.wav");
	Teleporteffect.setBuffer(Teleportsoundbuffer);
	Teleporteffect.setVolume(50);
	Teleportsoundbuffer2.loadFromFile("Sound/Teleport_sound.ogg");
	Teleporteffect2.setBuffer(Teleportsoundbuffer2);

	MangekyoSoundbuffer.loadFromFile("Sound/sharingan_sound.ogg");
	MangekyoEffect.setBuffer(MangekyoSoundbuffer);

	Deadsoundbuffer.loadFromFile("Sound/Deadeffect_sound.wav");
	Deadeffect.setBuffer(Deadsoundbuffer);
	Deadeffect.setVolume(40);

	ThemesoungBuffer.loadFromFile("Sound/Theme_song3.wav");
	Themesong_Song.setBuffer(ThemesoungBuffer);

}

Soundhead::~Soundhead()
{
}

void Soundhead::playsharingansound(bool& sharingan)
{
	if ((sharingan) and sharinganflag)
	{
		sharinganeffect.play();
		sharinganflag = false;
	}
	else if (!sharingan)
		sharinganflag = true;
}

void Soundhead::playTeleportsound(bool& teleport)
{
	if (teleport)
	{
		if (teleportflag2)
		{
			Teleporteffect.play();
			teleportflag2 = false;
		}
		if (teleportflag)
		{
			teleportoffset += 0.016;
			if (teleportoffset >= 0.4)
			{
				Teleporteffect2.play();
				teleportflag = false;
			}
		}
		
	}
	else if (!teleport)
	{
		teleportflag = true;
		teleportflag2 = true;
		teleportoffset = 0;
	}
}

void Soundhead::playMangekyoSound(bool& slash)
{
	if ((slash) and Mangekyoflag)
	{
		MangekyoEffect.play();
		Mangekyoflag = false;
	}
	else if (!slash)
	{
		Mangekyoflag = true;
	}

}

void Soundhead::playDeadSound(bool dead)
{
	if ((dead) and deadflag)
	{
		Deadeffect.play();
		deadflag = false;
	}
	if (!deadflag)
	{
		deadflag = true;
	}

}

void Soundhead::soundbackground()
{
	Themesong_Song.play();
	Themesong_Song.setLoop(true);
}
