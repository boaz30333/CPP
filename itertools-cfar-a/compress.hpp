#pragma once

using namespace std;

namespace itertools{
	template<typename T,typename B> 
    class compress{
		T container;
		B boole;
    
    public:
         compress(T m ,B boolean):container(m), boole(boolean){}

        class iterator {

	    private:
			typename T::iterator container_iter;
			typename T::iterator container_end;
			typename B::iterator bool_iter;
			typename B::iterator bool_end;

	    public:

		    iterator(typename T::iterator begins,typename T::iterator ends, typename B::iterator bool_begins,typename B::iterator bool_ends)
			: container_iter(begins), container_end(ends), bool_iter(bool_begins), bool_end(bool_ends) {
		    }

		auto operator*() {
			while(*(bool_iter)==false&&container_iter!=container_end){
            	container_iter++;
				bool_iter++;
			}
            //  if(container_iter==container_end)
            //  return;
            //   throw string("dfgdfgd");
            return *container_iter;
		}

		auto* operator->() {
			while(*(bool_iter)==false&&container_iter!=container_end){
            	container_iter++;
				bool_iter++;
			}
            //  if(container_iter==container_end)
            //  return;
            //   throw string("dfgdfgd");
            return *container_iter;
		}

		// ++i;
		iterator& operator++() {
			container_iter++;
            while(*(bool_iter)==false&&container_iter!=container_end){
            	container_iter++;
				bool_iter++;
			}
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			container_iter++;
            while(*(bool_iter)==false&&container_iter!=container_end){
            	container_iter++;
				bool_iter++;
			}
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
		return iterator{container.begin(),container.end(), boole.begin(), boole.end()};
	}
	
	iterator end() {
		return iterator{container.end(),container.end(), boole.end(), boole.end()};
	}
    };

}