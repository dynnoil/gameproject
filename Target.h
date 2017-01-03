#ifndef __TARGET_H__
#define __TARGET_H__

class Target {
	FPoint _position;
	float _speed;
	bool _alive;
	Render::Texture* _texture;
	TimedSpline<FPoint> _spline;
	void makeSplinePath();
public:
	Target();
	Target(FPoint position);
	void SetTexture(Render::Texture *texture);
	Render::Texture* GetTexture() const;
	TimedSpline<FPoint> const& GetSpline() const;
};

#endif // !__TARGET_H__