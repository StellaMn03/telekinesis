#include<iostream>

class musicians{
	public:
	static void play(){
		std::cout<<"The musician is performing";
	}
};
struct Mti{
	const char* name="musicians";
	const char* bases = {};
}mti;

struct mvtbl{
	Mti* ti = &mti;
	void (*play)() = &musicians::play;
};


class singer:public musicians{
	public:
        static void play(){
		std::cout<<"It's the singer's turn";
	}
};
struct Sti{
	const char* name="singer";
	const char* bases = {"musicians"};
}sti;
struct svtbl{
	Sti* ti = &sti;
	void (*play)() = &singer::play;
};



class piano:public musicians{
	public:
         static void play(){
		std::cout<<"It's the pianist's turn";
	}
};
struct Pti{
	const char* name = "piano";
	const char* bases = {"musicians"};
}pti;
struct pvtbl{
	Pti*  ti = &pti;
	void (*play)() = &piano::play;
};



class flute:public musicians{
	public:
	 static void play(){
		std::cout<<"It's the flutist's turn";
	}
};
struct Fti{
	const char* name = "flute";
	const char* bases = {"musicians"};
}fti;
struct fvtbl{
	Fti* ti = &fti;
	void (*play)() = &flute::play;
};



class drum:public musicians{
	public:
         static  void play(){
		std::cout<<"It's the drummer's turn";
	}
};
struct Dti{
	const char* name="drum";
	const char* bases = {"musicians"};
}dti;
struct dvtbl{
	Dti* ti= &dti;
	void (*play)() = &drum::play;
};




class guitar:public musicians{
	public:
	 static void play(){
		std::cout<<"It's the guitarist's turn";
	}
};
struct Gti{
	const char* name = "guitar";
	const char* bases = {"musicians"};
}gti;
struct gvtbl{
	Gti* ti = &gti;
	void (*play)() = &guitar::play;
};



class harp:public musicians{
	public:
         static	void play(){
		std::cout<<"It's the harpist's turn";
	}
};
struct Hti{
	const char* name="harp";
	const char* bases={"musicians"};
}hti;
struct hvtbl{
	Hti* ti = &hti;
	void (*play)() = &harp::play;
};




class violin:public musicians{
	public:
         static void play(){
		std::cout<<"It's the violinist's turn";
	}
};
struct Vti{
	const char* name="violin";
	const char* bases = {"musicians"};
}vti;
struct vvtbl{
	Vti* ti = &vti;
	void (*play)() = &violin::play;
};





class qanun:public musicians{
	public:
         static void play(){
        	std::cout<<"It's the qanunist's turn";
	}
};
struct Qti{
	const char* name="qanun";
	const char* bases = {"musicians"};
}qti;
struct qvtbl{
	Qti* ti = &qti;
	void (*play)() = &qanun::play;
};

