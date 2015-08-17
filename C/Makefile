SUBDIRS = adt misc

# all: $(LIB)
# 	for i in $(SUBDIRS); do \
# 		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
# 	done

# clean:
# 	for i in $(SUBDIRS); do \
# 		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
# 	done


.PHONY: subdirs lib $(SUBDIRS) clean

subdirs: $(SUBDIRS)

$(SUBDIRS): lib
	$(MAKE) -C $@

lib:
	$(MAKE) -C $@

clean:
	for dir in lib  $(SUBDIRS); do \
	$(MAKE) clean -C $$dir; \
	done
