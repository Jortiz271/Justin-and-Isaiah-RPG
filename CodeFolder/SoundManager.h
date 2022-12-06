#pragma once
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
private:
	// The buffers
	SoundBuffer m_Button;
	SoundBuffer m_SwordAttack;
	SoundBuffer m_GooAttack;
	SoundBuffer m_Death;
	SoundBuffer m_CookieMonster;

	// The Sounds
	Sound m_ButtonSound;
	Sound m_SwordAttackSound;
	Sound m_GooAttackSound;
	Sound m_DeathSound;
	Sound m_CookieMonsterSound;

	// Which sound should we use next, fire 1, 2 or 3
	int m_NextSound = 1;

public:

	SoundManager();

	void playButton();
	void playSwordAttack();
	void playGooAttack();
	void playDeathsound();
	void playCookieMonsterSound();
};