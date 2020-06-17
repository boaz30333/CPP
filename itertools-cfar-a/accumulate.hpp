#pragma once

using namespace std;

namespace itertools{

    typedef struct
    {
        template<typename R>
        R operator()(R x, R y){
            return x+y;
        }
    } standard;
    

    template<typename T, typename F=standard>
    class accumulate{
		T container;
        F func;
    public:
        accumulate(T m, F f = standard()): container(m), func(f){}

private:

    //-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	class iterator {

	  private:
		typename T::iterator itr;
        typename T::iterator endItr;
        decltype(*(container.begin())) value;
        F func;

	public:

		iterator(T::iterator m, T::iterator n, F fun): itr(n), endItr(n), func(fun), sum(*itr){}

		auto operator*() const {
			return value;
		}

		// T* operator->() const {
		// 	return &(pointer_to_current_node->m_value);
		// }

		// ++i;
		iterator& operator++() {
            itr++;
            if(itr!=endItr)
                value=func(value,*itr) ;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			itr++;
            value=value+*itr;
            // pointer_to_current_node= pointer_to_current_node->m_next;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return value == rhs.value;
		}

		bool operator!=(const iterator& rhs) const {
			return value != rhs.value;
		}
	};  // END OF CLASS ITERATOR

public:

	iterator begin() {
		return iterator(container.begin(), container.end(), func);
	}
	
	iterator end() {
		return iterator{container.end(), container.end(), func};
	}
    };
}