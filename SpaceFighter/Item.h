
#pragma once
#include "BioEnemyShip.h"
#include "Level.h"
class Item : public BioEnemyShip
{
public:
	void Activate(const Vector2 position, const float scale);
	void Draw(SpriteBatch& spriteBatch);
	bool IsActive();
private:
	int m_scale;
	int m_rotation;
	bool m_Active = false;
	Texture* m_pTexture = nullptr;

};

