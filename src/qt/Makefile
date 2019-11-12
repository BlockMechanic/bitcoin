.PHONY: FORCE
all: FORCE
	$(MAKE) -C .. cypher_qt test_cypher_qt
clean: FORCE
	$(MAKE) -C .. cypher_qt_clean test_cypher_qt_clean
check: FORCE
	$(MAKE) -C .. test_cypher_qt_check
cypher-qt cypher-qt.exe: FORCE
	 $(MAKE) -C .. cypher_qt
