#pragma once

using namespace std;

namespace itertools{
    class range{
        int begins;
        int ends;

    public:
        range(int begin, int end):begins(begin), ends(end){}

        class iterator {

	    private:
		    int current;

	    public:

		    iterator(int num = 0)
			: current(num) {
		    }

		int& operator*() {
			//return *pointer_to_current_node;
            return current;
		}

		int* operator->() {
			return &current;
		}

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
			current++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			current++;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const iterator& rhs) const {
			return current != rhs.current;
		}
	};  // END OF CLASS ITERATOR

	iterator begin() {
		return iterator{begins};
	}
	
	iterator end() {
		return iterator{ends};
	}
    };




	template<typename T>
    class accumulate{
        // decltype(*(typename T::iterator)) begins;
        // decltype(*(typename T::iterator)) ends;
		T& container;
		decltype(*(begin(container))) begins;
		// decltype(typename T::iterator_traits<typename T::iterator>) begins;
		decltype(*(end(container))) ends;
        // typename iterator_traits<typename T::template::iterator>::value_type ends;
        // T& container;

    public:
        accumulate(T m): container(m), begins{*(m.begin())}, ends{*(m.end())}{
			// begins=*(m.begin());
			// ends=*(m.end());
		}

private:

    //-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	class iterator {

	  private:
		typename T::iterator itr;
        decltype(*(itr)) value;

	public:

		iterator(T m)
			: itr(m.begin()), value(*itr) {
                // value=*itr;
		}

        // iterator(T m)
		// 	: itr(m) {
        //         value=*itr;
		// }

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		auto operator*() const {
			//return *pointer_to_current_node;
			return value;
		}

		// T* operator->() const {
		// 	return &(pointer_to_current_node->m_value);
		// }

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
            itr++;
            value=value+*itr;
			// pointer_to_current_node = pointer_to_current_node->m_next;
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
		return iterator(container);
	}
	
	iterator end() {
		return iterator{container};
	}
    };
}