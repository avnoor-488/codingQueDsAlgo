#include<iostream>
#include<algorithm>
#include<vector>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& ls)
{
	out<<'[';
	
	for(auto i = ls.begin(); i != ls.end(); ++i)
		out<<*i<<(i + 1 == ls.end() ? "" : ", ");
	
	out<<']';

	return out;
}

template<typename Container>
void binary_insertion_sort(Container& ctx)
{
	for(auto a = ctx.begin(); a != ctx.end(); ++a)
		std::rotate(
				std::upper_bound(ctx.begin(), a, *a),
				a,
				a + 1
			); 
	
}

int main()
{
	std::vector<int> vec = {90, 1, 20, 45, 0, 18, 3};
	std::cout<<"The vector before sorting "<<vec<<std::endl;
	binary_insertion_sort(vec);
	std::cout<<"After sorting "<<vec<<std::endl;
}
