 #pragma once



 namespace itertools{
	  using namespace std;
        // typedef struct {
        //         template <typename K>
        //         bool operator ()(K b) const {
        //                 return a+b;
        //         }
        // } add;
	template<typename F ,typename T> 
    class filterfalse{
	T container;
	F func;
    public:
        filterfalse(F function,T m):container(m),func(function){
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
            while(func(*container_iter)&&container_iter!=container_end)
            container_iter++;
             if(container_iter==container_end)
             return;
            //   throw string("dfgdfgd");
            return *container_iter;
		}

		auto* operator->() {
            while(func(*container_iter)&&container_iter!=container_end)
            container_iter++;
             if(container_iter==container_end) 
             return;
            //   throw string("dfgdfgd");
			return *container_iter;
		}

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
			container_iter++;
            while(func(*container_iter)&&container_iter!=container_end)
            container_iter++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
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
		return iterator(container.begin(),container.end(),func);
	}
	
	iterator end() {
return iterator(container.end(),container.end(),func);
	}
    };




// 	template<typename T>
//     class filterfalse{
//         // decltype(*(typename T::iterator)) begins;
//         // decltype(*(typename T::iterator)) ends;
// 		T& container;
// 		decltype(*(begin(container))) begins;
// 		// decltype(typename T::iterator_traits<typename T::iterator>) begins;
// 		decltype(*(end(container))) ends;
//         // typename iterator_traits<typename T::template::iterator>::value_type ends;
//         // T& container;

//     public:
//         filterfalse(T m): container(m), begins{*(m.begin())}, ends{*(m.end())}{
// 			// begins=*(m.begin());
// 			// ends=*(m.end());
// 		}

// private:

//     //-------------------------------------------------------------------
// 	// iterator related code:
// 	// inner class and methods that return instances of it)
// 	//-------------------------------------------------------------------
// 	class iterator {

// 	  private:
// 		typename T::iterator itr;
//         decltype(*(itr)) value;

// 	public:

// 		iterator( T:iterator m)
// 			: itr(m), value(*itr) {
//                 // value=*itr;
// 		}

//         // iterator(T m)
// 		// 	: itr(m) {
//         //         value=*itr;
// 		// }

// 		// Note that the method is const as this operator does not
// 		// allow changing of the iterator.
// 		// Note that it returns T& as it allows to change what it points to.
// 		// A const_iterator class will return const T&
// 		// and the method will still be const
// 		auto operator*() const {
// 			//return *pointer_to_current_node;
// 			return value;
// 		}

// 		// T* operator->() const {
// 		// 	return &(pointer_to_current_node->m_value);
// 		// }

// 		// ++i;
// 		iterator& operator++() {
// 			//++pointer_to_current_node;
//             itr++;
//             value=value+*itr;
// 			// pointer_to_current_node = pointer_to_current_node->m_next;
// 			return *this;
// 		}

// 		// i++;
// 		// Usually iterators are passed by value and not by const& as they are small.
// 		const iterator operator++(int) {
// 			iterator tmp= *this;
// 			itr++;
//             value=value+*itr;
//             // pointer_to_current_node= pointer_to_current_node->m_next;
// 			return tmp;
// 		}

// 		bool operator==(const iterator& rhs) const {
// 			return value == rhs.value;
// 		}

// 		bool operator!=(const iterator& rhs) const {
// 			return value != rhs.value;
// 		}
// 	};  // END OF CLASS ITERATOR

// public:

// 	iterator begin() {
// 		return iterator(container.end());
// 	}
	
// 	iterator end() {
// 		return iterator{container.begin()};
// 	}
//     };
}