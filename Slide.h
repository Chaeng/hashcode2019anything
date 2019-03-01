#include <set>

class Slide {

private:
	int ID;
	set<string> tagsSet;
	vector<Picture> picList;

public:
	Slide(int id) { ID = id; };
	void addPicture(Picture p) {
		picList.push_back(p);
	}

	vector<Picture> getPicList() {
		return picList;
	}

	int getID() { return ID; }

	int getTagsListSize() { return tagsSet.size(); }
};

