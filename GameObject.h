#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

class GameObject {
	Render::Texture* _texture;
	bool _alive;
protected:
	FPoint _position;
	FPoint _direction;
	float _velocity;
public:
	GameObject(Render::Texture* texture);
	virtual ~GameObject() {}
	void Kill();
	void ChangeDirection(FPoint point);
	Render::Texture* GetTexture() const;
	bool IsAlive() const;
	FPoint GetPosition() const;
	FPoint GetCenter() const;
	IRect GetRecatngle() const;
	FPoint GetDirection() const;
	virtual void Move() = 0;
};

#endif // !__GAMEOBJECT_H__