#include "reader.h"
#include "sorter.h"
#include "finder.h"

int main(int argc, char* argv[])
{
	if (argc !=3) {
		std::cerr << "error!" << std::endl;
		return 0;
	}
	Module1::File x(argv[1]);
	if (x.open_file() == 2) {
		std::cerr << "invailed file name" << std::endl;
		return 0;
	}
	x.count_words();
	Module2::Sort m(x.Getmap());
	m.create();
	Module3::OutWords y(argv[2]);
	if (y.open_out() == 2) {
		std::cout << "output file did not open" <<std::endl;
		return 0;
	}
	y.write_to_file(m.Getvector(), x.Getcount());
	return 0;
}