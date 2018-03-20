.PHONY: clean All

All:
	@echo "----------Building project:[ problem151 - Debug ]----------"
	@cd "problem151" && "$(MAKE)" -f  "problem151.mk"
clean:
	@echo "----------Cleaning project:[ problem151 - Debug ]----------"
	@cd "problem151" && "$(MAKE)" -f  "problem151.mk" clean
