#pragma once



 namespace itertools{
	  using namespace std;
        typedef struct {
                template <typename K>
                K operator ()(K a, K b) const {
                        return a+b;
                }
        } add;
	template<typename T,typename F = add> 
    class accumulate{
	T container;
	F func;
    public:
        accumulate(T m ,F function = add()):container(m),func(function){
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
iterator(const iterator& other):container_iter(other.container_iter),container_end(other.container_end),func(other.func),data(*(other.container_iter)){
		    }

		auto operator*() {
            return data;
		}

		auto* operator->() {
			return data;
		}

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
			container_iter++;
			// iter= *container_iter;
			if(container_iter!=container_end)
			data= func(data,*container_iter);
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			container_iter++;
			if(container_iter!=container_end)
			data= func(data,*container_iter);
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
		return iterator(container.begin(),container.end(),func);
	}
	
	iterator end() {
return iterator(container.end(),container.end(),func);
	}
    };
}