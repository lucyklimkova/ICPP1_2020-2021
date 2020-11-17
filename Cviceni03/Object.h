#ifndef OBJECT_H
#define OBJECT_H

class Object {
	int id;
	double x;
	double y;
public:
	Object() = delete;
	Object(int id);
	virtual ~Object() { }
	int GetId() const;
	double GetX() const;
	void SetX(double x);
	double GetY() const;
	void SetY(double y);
};

#endif // !OBJECT_H