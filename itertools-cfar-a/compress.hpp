 #pragma once



 namespace itertools{
	  using namespace std;
	template<typename K ,typename T> 
    class compress{
	T bool_c;
	K cont;
    public:
        compress(K con,T m):cont(con),bool_c(m){
		}

        class iterator {
	    private:
		typename K::iterator container_iter;
		typename K::iterator container_end;
		typename T::iterator bool_iter;
		typename T::iterator bool_end;
	    public:
		    iterator(typename K::iterator begins,typename K::iterator ends,typename T::iterator b_begins,typename T::iterator b_ends)
			: container_iter(begins),container_end(ends),bool_iter(b_begins),bool_end(b_ends){
		    }
iterator(const iterator& other):container_iter(other.container_iter),container_end(other.container_end),bool_iter(other.bool_iter),bool_end(other.bool_end){
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
            bool_iter++;
        while((*bool_iter)==false&&container_iter!=container_end&&bool_iter!=bool_end)
            {
                container_iter++;
                bool_iter++;
            }
        if((container_iter!=container_end&&bool_iter==bool_end)||(container_iter==container_end&&bool_iter!=bool_end))
            throw string("error- containers no same size");
			return *this;
		}


		const iterator operator++(int) {
			iterator tmp= *this;
			container_iter++;
            bool_iter++;
        while((*bool_iter)==false&&container_iter!=container_end&&bool_iter!=bool_end)
            {
                container_iter++;
                bool_iter++;
            }
        if((container_iter!=container_end&&bool_iter==bool_end)||(container_iter==container_end&&bool_iter!=bool_end))
            throw string("error- containers no same size");
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return container_iter == rhs.container_iter;
		}

		bool operator!=(const iterator& rhs) const {
			return !(container_iter == rhs.container_iter && bool_iter ==rhs.bool_iter);
		}
	};  // END OF CLASS ITERATOR

	iterator begin() {
      typename  K::iterator cb =cont.begin();
typename T::iterator bb= bool_c.begin();
        while((*bb)==false&&cb!=cont.end()&&bb!=bool_c.end())
            {
                cb++;
                bb++;
            }
        if((cb!=cont.end()&&bb==bool_c.end())||(cb==cont.end()&&bb!=bool_c.end()))
            throw string("error- containers no same size");

		iterator first(cb,cont.end(),bb,bool_c.end());
		return first;

	}
	
	iterator end() {
return iterator(cont.end(),cont.end(),bool_c.end(),bool_c.end());
	}
    };
}