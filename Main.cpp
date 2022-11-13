#include "Common.hpp"
#include "FileStream.hpp"

bool copyFile(const char* src, const char* dest) {
	std::ifstream source(src, std::ios::binary);
	std::ofstream destination(dest, std::ios::binary);
	destination << source.rdbuf();
	return source && destination;
}

int main(int argc, char* argv[]) {
	fs::path path(std::getenv("appdata"));
	fs::path fontName{ argv[1] };
	std::string fontId{ argv[2] };
	for (int i{}; i != argc; ++i) {
		if (i != 0 && i != 1 && i != 2) {
			fontId += " " + std::string(argv[i]);
		}
	}
	path.append("GFXFontCreation");
	if (!fs::exists(path)) {
		fs::create_directories(path);
		system(std::format("move Files {}", path.string()).c_str());
	}
	path.append("Files");
	auto e = CopyFileA(fontName.string().c_str(), fs::path(path).append(fontName.string()).string().c_str(), false);
	if (!e) {
		std::cout << "Error: " << GetLastError() << std::endl;
	}
	else {
		std::cout << "Successfully copied the font" << std::endl;
	}
	fileStream xml_fs(fs::path(path).append("in.xml"));
	xml_fs.write(std::format(R"(<?xml version="1.0" encoding="iso-8859-1" ?>

<movie version="8" width="320" height="240" framerate="12">
  <frame>
    <library>
      <font id="{}" import="{}" name="{}"/>
    </library>
  </frame>
</movie>)", fontId, fontName.string(), fontId));
	xml_fs.finish();
	system(std::format("{} simple {}.xml {}.swf", fs::path(path).append("swfmill.exe").string(), fs::path(path).append("in").string(), fontName.stem().string()).c_str());
	std::this_thread::sleep_for(1000ms);
	system(std::format("{} {}.swf", fs::path(path).append("gfxexport.exe").string(), fontName.stem().string()).c_str());
	remove(fs::path(path).append(fontName.string()).string().c_str());
	remove(std::format("{}.swf", fontName.stem().string()).c_str());
	for (;;) {
		if (GetAsyncKeyState(VK_F4))
			break;
	}
	return 0;
}