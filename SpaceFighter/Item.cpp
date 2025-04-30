#include "Item.h"
void Item::Activate(const Vector2 position, const float scale)
{
	SetPosition(position);
	m_scale = scale;
	m_rotation = Math::GetRandomFloat() * 2 * Math::PI;
	//m_pAnimation->Play();
	//if (m_pSound) m_pSound->Play();
	m_Active = true;

}
void Item::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(GetTexture(), GetPosition(), Color::WHITE * alpha, GetTexture()->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
bool Item::IsActive() {
	return m_Active;
}