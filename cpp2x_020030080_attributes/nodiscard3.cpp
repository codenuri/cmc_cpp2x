enum class [[nodiscard]] ErrorCode { OK, WARNING, CRITICAL, FATAL };

ErrorCode foo() { return ErrorCode::CRITICAL; }

int main()
{
    auto ret = foo();	// ok

	foo(); // warning
}
