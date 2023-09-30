/* Greeter.h */

#ifndef GREETER_H
#define GREETER_H

#ifdef ADDRESSING_SOMEONE_EXPORT
#define ADDRESSING_SOMEONE_DLL __declspec(dllexport)
#else
#define ADDRESSING_SOMEONE_DLL __declspec(dllimport)
#endif

#include <string>

namespace bag {
	class ADDRESSING_SOMEONE_DLL Greeter {
	public:
		Greeter(const std::string & = "Здравствуйте, ");
		~Greeter();

		const std::string greet(const std::string&) const;

	private:
		std::string message_{};
	};
}

#endif /* GREETER_H */