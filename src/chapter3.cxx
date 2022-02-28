module;
export module Chapter3;
export{
void func();
template <typename T>
class MyVector{

public:
	MyVector();
private:
	T* elements;
	const int MIN_SIZE = 16;
};
}
