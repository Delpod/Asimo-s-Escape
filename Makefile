.PHONY: clean All

All:
	@echo "----------Building project:[ asimos_escape - Release ]----------"
	@$(MAKE) -f  "asimos_escape.mk"
clean:
	@echo "----------Cleaning project:[ asimos_escape - Release ]----------"
	@$(MAKE) -f  "asimos_escape.mk" clean
