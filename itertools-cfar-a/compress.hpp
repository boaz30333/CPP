<<<<<<< HEAD
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

=======
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
>>>>>>> af6c4e7f36c545216bef77947db242e4bcb460a5
            return *container_iter;
		}

		auto* operator->() {
<<<<<<< HEAD

			return *container_iter;
=======
			while(*(bool_iter)==false&&container_iter!=container_end){
            	container_iter++;
				bool_iter++;
			}
            //  if(container_iter==container_end)
            //  return;
            //   throw string("dfgdfgd");
            return *container_iter;
>>>>>>> af6c4e7f36c545216bef77947db242e4bcb460a5
		}

		// ++i;
		iterator& operator++() {
			container_iter++;
<<<<<<< HEAD
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
=======
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
>>>>>>> af6c4e7f36c545216bef77947db242e4bcb460a5
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return container_iter == rhs.container_iter;
		}

		bool operator!=(const iterator& rhs) const {
<<<<<<< HEAD
			return !(container_iter == rhs.container_iter && bool_iter ==rhs.bool_iter);
=======
			return !(container_iter == rhs.container_iter);
>>>>>>> af6c4e7f36c545216bef77947db242e4bcb460a5
		}
	};  // END OF CLASS ITERATOR

	iterator begin() {
<<<<<<< HEAD
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
=======
		return iterator{container.begin(),container.end(), boole.begin(), boole.end()};
	}
	
	iterator end() {
		return iterator{container.end(),container.end(), boole.end(), boole.end()};
	}
    };

>>>>>>> af6c4e7f36c545216bef77947db242e4bcb460a5
}