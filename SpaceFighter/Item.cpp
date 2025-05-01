#include "Item.h"
Item::Item() {
	SetActive(false);
	m_Active = false;
}
void Item::Activate(const Vector2 position, const float scale)
{
	SetPosition(position);
	m_scale = scale;
	m_rotation = Math::GetRandomFloat() * 2 * Math::PI;
	//m_pAnimation->Play();
	//if (m_pSound) m_pSound->Play();
	m_Active = true;
	SetActive(true);
}
void Item::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		srand(time(NULL));
		Color color = Color::WHITE;
		int i = rand() % 5;
		switch (i) {
		case 0:
			color = Color::BLUE;
			break;
		case 1:
			color = Color::PURPLE;
			break;
		case 2:
			color = Color::YELLOW;
			break;
		case 3:
			color = Color::RED;
			break;
		case 4:
			color = Color::GREEN;
			break;
		}
		spriteBatch.Draw(GetTexture(), GetPosition(), color * alpha, GetTexture()->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
bool Item::IsActive() {
	return m_Active;
}
void Item::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		TranslatePosition(0, GetSpeed() * 0.35 * gameTime.GetElapsedTime());

		if (!IsOnScreen()) Deactivate();
		GetCurrentLevel()->UpdateSectorPosition(this);
	}
	//EnemyShip::Update(gameTime);
}
void Item::Deactivate() {
	m_Active = false;
	SetActive(false);
}