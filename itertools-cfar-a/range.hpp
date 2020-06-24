#pragma once

using namespace std;

namespace itertools{
    class range{
        int begins;
        int ends;

    public:
        range(int begin, int end):begins(begin), ends(end){}
// int operator[] (int index){
// 	return *(iterator(begins));
// }
        class iterator {

	    private:
		    int current;

	    public:

		    iterator(int num = 0)
			: current(num) {
		    }

		int operator*() {
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
		return iterator(begins);
	}
	
	iterator end() {
		return iterator(ends);
	}
    };
}