 #pragma once



 namespace itertools{
	  using namespace std;

	template<typename F ,typename T> 
    class filterfalse{
	T container;
	F func;
    public:
        filterfalse(const F& function,const T& m):container(m),func(function){
		}

        class iterator {
	    private:
		typename T::iterator container_iter;
		typename T::iterator container_end;

		decltype(*(container_iter))  data ;
			 F func;
	    public:
		    iterator(typename T::iterator begins,typename T::iterator ends,F function)
			: container_iter(begins),container_end(ends),func(function),data(*begins){
		    }
iterator(const iterator& other):container_iter(other.container_iter),container_end(other.container_end),func(other.func),data(other.data){
		    }

		auto operator*() {
            return *container_iter;
		}

		auto* operator->() {
			return *container_iter;
		}

		// ++i;
		iterator& operator++() {
			container_iter++;
            while(func(*container_iter)&&container_iter!=container_end)
            	container_iter++;
			return *this;
		}


		const iterator operator++(int) {
			iterator tmp= *this;
			container_iter++;
            while(func(*container_iter)&&container_iter!=container_end)
            	container_iter++;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return container_iter == rhs.container_iter;
		}

		bool operator!=(const iterator& rhs) const {
			return !(container_iter == rhs.container_iter);
		}
	};  // END OF CLASS ITERATOR

	iterator begin() {
		iterator first(container.begin(),container.end(),func);
		 while(func(*first)&&first!= end())
		 first++;
		return first;

	}
	
	iterator end() {
return iterator(container.end(),container.end(),func);
	}
    };
}
