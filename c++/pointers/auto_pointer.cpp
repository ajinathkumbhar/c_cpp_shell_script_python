#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

class mediaPlayer {
public:
	void show() {
		cout << "show file src" << '\n';
	}
};

int main(int argc, const char * argv[]) {
	auto_ptr<mediaPlayer> mPlayer(new mediaPlayer);
	mPlayer->show();
	cout << "mPlayer : " << mPlayer.get() << '\n';

	auto_ptr<mediaPlayer> mPlayer_new(mPlayer);
	mPlayer_new->show();
	cout << "mPlayer : " << mPlayer.get() << '\n';

	unique_ptr<mediaPlayer> mPlayer_unique(new mediaPlayer);
	mPlayer_unique->show();
	cout << "mPlayer_unique.get() : " << mPlayer_unique.get()<< '\n';

	unique_ptr<mediaPlayer> mPlayer_unique1 = move(mPlayer_unique);
	cout << "mPlayer_unique.get() : " << mPlayer_unique.get()<< '\n';
	cout << "mPlayer_unique1.get() : " << mPlayer_unique1.get()<< '\n';

	shared_ptr<mediaPlayer> mPlayer_shared(new mediaPlayer);
	cout << "mPlayer_shared.get() : " << mPlayer_shared.get()<< '\n';
	cout << "mPlayer_shared.use_count() : " << mPlayer_shared.use_count()<< '\n';
	shared_ptr<mediaPlayer> mPlayer_shared1(mPlayer_shared);
	cout << "mPlayer_shared.use_count() : " << mPlayer_shared.use_count()<< '\n';
	cout << "mPlayer_shared1.use_count() : " << mPlayer_shared1.use_count()<< '\n';

	return EXIT_SUCCESS;	
}