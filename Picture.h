

#include <string>
#include <vector>
using namespace std;

extern struct Tags {
	vector<string> list;
};

class Picture {

	private:
		int ID;
		int numTags;
		Tags tags;
		string Orient;

	public:
		int getID() { return ID; };
		Picture(int id, string orient) { ID = id; Orient = orient; };
		void addNumTags(int nT) { numTags = nT; };
		void addTag(string tag) { tags.list.push_back(tag); };

		string getType() { return Orient; }

		Tags getTags() {
			return tags;
		}
};