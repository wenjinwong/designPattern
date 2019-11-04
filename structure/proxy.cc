class image;

extern image* loadanimagefile(const char*);

class imageptr{
	public:
		imageptr(const char* imagefile);
		virtual ~imageptr();

		virtual image* operator->();
		virtual image& operator*();
	private:
		image* loadimage();
	private:
		image *_image;
		const char* _imageFile;
};


imageptr::imageptr(const char* theImageFile) {
	_imageFile = theImageFile;
	_image = 0;
}

image* imageptr::loadimage() {
	if(_image == 0) {
		_image = loadanimagefile(_imageFile);
	}
	return _image;
}

image* imageptr::operator->() {
	return loadimage();
}

image* imageptr::operator*() {
	return *loadimage();
}
