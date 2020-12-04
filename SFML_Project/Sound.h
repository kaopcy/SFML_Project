#pragma once
#include "Defination.h"
class Soundhead
{
public:
	Soundhead();
	virtual ~Soundhead();
	void playsharingansound(bool &sharingan);
	void playTeleportsound(bool& teleport);
	void playMangekyoSound(bool& slash);
	void playDeadSound(bool dead);
	void soundbackground();


private:
	sf::SoundBuffer sharingansoundbuffer;
	sf::Sound sharinganeffect;

	sf::SoundBuffer Teleportsoundbuffer;
	sf::Sound Teleporteffect;
	sf::SoundBuffer Teleportsoundbuffer2;
	sf::Sound Teleporteffect2;

	sf::SoundBuffer MangekyoSoundbuffer;
	sf::Sound MangekyoEffect;

	sf::SoundBuffer Deadsoundbuffer;
	sf::Sound Deadeffect;

	sf::SoundBuffer ThemesoungBuffer;
	sf::Sound Themesong_Song;	

	bool sharinganflag = true;
	bool teleportflag = true;
	bool teleportflag2 = true;
	bool Mangekyoflag = true;
	bool deadflag = true;

	float teleportoffset = 0;
};

