#ifndef EP_DEBUGTEXT_OVERLAY_H
#define EP_DEBUGTEXT_OVERLAY_H

#include <map>
#include <vector>
#include <string>
#include "drawable.h"
#include "rect.h"
#include "memory_management.h"

struct DebugTextOverlayItem {
	bool show = false;
	bool dirty = false;
	bool remove = false;
	Rect rect;
	std::vector<std::string> lines;
};

class DebugTextOverlay : public Drawable {
public:
	DebugTextOverlay();

	void Draw(Bitmap& dst) override;

	void UpdateItem(const std::string& name, const std::string& debugtext);
	void ShowItem(const std::string& name);
	void HideItem(const std::string& name);
	void RemoveItem(const std::string& name);

	void SetColor(int color);

private:
	Rect bitmap_rect;
	BitmapRef bitmap;

	std::map<std::string, DebugTextOverlayItem> items;
	std::vector<std::string> remove_list;

	int color = 0;
};

#endif
