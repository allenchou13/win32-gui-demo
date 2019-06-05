#include "trial_control.h"

#include <string>
#include <vector>

std::string points = "7.56 20.51 27.56 14.51 63.56 0.51 131.56 10.51 125.56 20.51 123.56 54.51 82.56 63.51 64.56 49.51 59.56 70.51 47.56 88.51 27.56 88.51 19.56 83.51 19.56 59.51 15.56 48.51 0.56 35.51 6.56 12.51 7.56 20.51";

std::vector<std::string> split(std::string src,
	std::string spliter) {
	std::vector<std::string> rlt;
	int pos = 0;
	int start_pos = 0;
	while (true) {
		pos = src.find(spliter, start_pos);
		if (pos != std::string::npos) {
			rlt.push_back(src.substr(start_pos, pos - start_pos));
		}
		else {
			if (start_pos < src.length()) {
				rlt.push_back(src.substr(start_pos));
			}
			break;
		}

		start_pos = pos + spliter.length();
	}
	return rlt;
}

std::vector<POINT> get_points() {
	std::vector<std::string> num_str_list = split(points, " ");
	std::vector<double> num_list;
	for (auto i = 0; i < num_str_list.size(); i++) {
		num_list.push_back(std::stod(num_str_list[i]));
	}
	std::vector<POINT> pts;
	for (int i = 0; i < num_list.size() / 2; i++) {
		auto p = POINT();
		p.x = num_list[2 * i];
		p.y = num_list[2 * i + 1];
		pts.push_back(p);
	}
	return pts;
}

void TrialControl::paint(HDC hdc, RECT rect) {
	COLORREF color = 0x00dcdcdc;
	for (int i = 10; i < 200; i++) {
		for (int j = 10; j < 200; j++) {
			SetPixel(hdc, i, j, color);
		}
	}
	SetDCBrushColor(hdc, color);
	RoundRect(hdc, 10, 150, 110, 250, 5, 5);
	std::vector<POINT> pts = get_points();
	Polygon(hdc, pts.data(), pts.size());
	/*DrawText(hdc, TEXT("Hello, Windows 98!"), -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/
}