#pragma once
class Camera
{
public:
	Camera(float width, float height);
	Camera(const Camera& camera) = delete;
	Camera& operator=(const Camera& camera) = delete;
	~Camera() = default;
	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Transform(const Rectf& target);
	Point2f GetCameraPos() const;

private:
	float m_Width;
	float m_Height;
	Rectf m_LevelBoundaries;
	Point2f m_NewCameraPos;

	void Clamp(Point2f& bottomLeftPos) const;
	Point2f Track(const Rectf target) const;

};

