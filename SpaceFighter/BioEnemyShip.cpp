
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		srand(time(NULL));
		float x = (sin(gameTime.GetTotalTime() * Math::PI + GetIndex()));
		x *= (GetSpeed()/2) * gameTime.GetElapsedTime() + (rand()%14) - (rand()%14);
		TranslatePosition(x, GetSpeed()*1.25 * gameTime.GetElapsedTime());

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
