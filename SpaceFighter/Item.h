
#pragma once
#include "BioEnemyShip.h"
#include "Level.h"
class Item : public BioEnemyShip
{
public:
	Item();
	void Activate(const Vector2 position, const float scale);
	void Draw(SpriteBatch& spriteBatch);
	bool IsActive();
	void Update(const GameTime& gameTime);
	virtual CollisionType GetCollisionType() const { return CollisionType::Item; }
	void Item::Deactivate();
private:
	int m_scale;
	int m_rotation;
	bool m_Active = false;
	bool m_isActive = false;
	Texture* m_pTexture = nullptr;

};

