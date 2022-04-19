#include <stdio.h>
#include <functional>

 template<typename t>
class array
{
protected:
 t*self;
 size_t size;
public:
	array(const size_t size)
	:
		size(size),
		self(new t[size])
	{}
	 template<class...init>
	array(init...args)
	:
		size(sizeof...(args)),
		self(new t[size]{args...})
	{}
	array(const array&a)
	:
		size(a.self),
		self(a.size)
	{}

	 inline
	t&operator[](const size_t id)
	{if(id<size)return self[id];else exit(1);}

	void operator()(std::function<void(t&e)>f)
	{for(size_t i=0;i<size;i++)f(self[i]);}
};

int main()
{
 array<int>test(5,3,1,1);
 test([](int&i){i++;});
 test([](int&i){printf("%d\n",i);})
 
 return 0;
}
