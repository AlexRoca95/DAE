#pragma once
class Camera
{
public:
	Camera(float width, float height);
	~Camera() = default;
	Camera(const Camera& level) = delete;
	Camera(Camera&& gameObject) = delete;
	Camera& operator=(const Camera& level) = delete;
	Camera& operator=(Camera&& camera) = delete;

	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Transform(const Rectf& target) const;

private:

	float m_Width;
	float m_Height;
	Rectf m_LevelBoundaries;
	

	void Clamp(Point2f& bottomLeftPos) const;
	Point2f Track(const Rectf target) const;
};

