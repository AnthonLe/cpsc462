#ifndef UI_UIHandler_h
#define UI_UIHandler_h



namespace UI
{
	// User Interface Layer Abstract class
	struct UIHandler
	{
		// Constructors and assignment operations
		UIHandler() = default;    // default ctor
		UIHandler(const UIHandler &  original) = default;    // copy ctor
		UIHandler(UIHandler && original) = default;    // move ctor

		virtual UIHandler & operator=(const UIHandler &  rhs) = default;    // copy assignment
		virtual UIHandler & operator=(UIHandler && rhs) = default;    // move assignment

		// Operations
		virtual void launch() = 0;


		// Abstract class destructor
		virtual ~UIHandler() noexcept = 0;  // must be virtual and pure
	};


	/*****************************************************************************
	** Inline implementations
	******************************************************************************/
	inline UIHandler::~UIHandler() noexcept
	{}


} // namespace UI



#endif // UI_UIHandler_h

