/* Leaver.h */

#ifndef LEAVER_H
#define LEAVER_H

#ifdef ADDRESSING_SOMEONE_EXPORT
#define ADDRESSING_SOMEONE_DLL __declspec(dllexport)
#else
#define ADDRESSING_SOMEONE_DLL __declspec(dllimport)
#endif

#include <string>

namespace bag {
	class ADDRESSING_SOMEONE_DLL Leaver {
	public:
		Leaver(const std::string & = "До свидания, ");
		~Leaver();

		const std::string leave(const std::string&) const;

	private:
		std::string message_{};
	};
}
#endif /* LEAVER_H */