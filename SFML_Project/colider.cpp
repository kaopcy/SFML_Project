#include "colider.h"
colider::colider(sf::RectangleShape body)  //รับค่า body เข้ามา แล้วกำหนดให้ body ที่รับเข้ามาจาก parameter = body ที่อยู่ใน class 
	:body(body)
{
}

colider::~colider()
{
}

bool colider::checkcolider(colider body, colider push) // colider คือการสร้าง obj ขึ้นมาอีกตัวโดยที่จะสามารถใช้งานทุกอย่างที่เป้น public ของ แสฟหห wfh
{
	sf::Vector2f otherposition = body.getposition();
	sf::Vector2f otherhalfsize = body.gethalfsize();
	sf::Vector2f thisposition = getposition();
	sf::Vector2f thishalfsize = gethalfsize();

	float deltaX = otherposition.x - thisposition.x;
	float deltaY = otherposition.y - thisposition.y;
	float intersectX = abs(deltaX) - (thishalfsize.x + otherhalfsize.x);
	float intersectY = abs(deltaY) - (thishalfsize.y + otherhalfsize.y);
	if (intersectX < 0.0f and intersectY < 0.0f)
	{
		return true;
	}
	return false;
}
