namespace vm {

    class View {
    public:
        View(int height, int width, int startX, int startY);
        ~View();

        void printBufferContent();
        void setHighlighter(std::unique_ptr<Highlighter> highlighter);
        void resetCursor();
        virtual void printString(const std::string& text) const;
        int height() const;
        void setBackgroundColor(int pair);

        void enableHighlightingAt(int xStart, int xFinish, int y);
        void disableHighlighting();

    private:
        void setCursorAt(int x, int y);
        void clearView() const;

        int _height;
        std::string _content;
        std::pair<std::pair<int, int>, int> _highlight;
        WINDOW* _window;
        std::shared_ptr<Buffer> _buffer;
        std::unique_ptr<Highlighter> _highlighter;
        std::unique_ptr<ViewCursor> _cursor;
    };
}
