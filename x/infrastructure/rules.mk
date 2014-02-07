# This assumes that many variables have been pre-defined:
# _SRC: source file
# _OBJ: destination file
# _CC: 'compiler' command
# _FLAGS: 'compiler' flags
# _TEXT: Display text (e.g. "Compile++ thumb", must be EXACTLY 15 chars long)
#
define ev-build-file
$$(_OBJ): PRIVATE_SRC      := $$(_SRC)
$$(_OBJ): PRIVATE_OBJ      := $$(_OBJ)
$$(_OBJ): PRIVATE_DEPS     := $$(call host-path,$$(_OBJ).d)
$$(_OBJ): PRIVATE_MODULE   := $$(X_MODULE)
$$(_OBJ): PRIVATE_TEXT     := "$$(_TEXT)"
$$(_OBJ): PRIVATE_CC       := $$(_CC)
$$(_OBJ): PRIVATE_CFLAGS   := $$(_FLAGS)

$$(call generate-file-dir,$$(_OBJ))

$$(_OBJ): $$(_SRC) $$(LOCAL_MAKEFILE) $$(NDK_APP_APPLICATION_MK) $$(NDK_DEPENDENCIES_CONVERTER)
	@$$(HOST_ECHO) "$$(PRIVATE_TEXT)  : $$(PRIVATE_MODULE) <= $$(notdir $$(PRIVATE_SRC))"
	$$(hide) $$(PRIVATE_CC) -MMD -MP -MF $$(call convert-deps,$$(PRIVATE_DEPS)) $$(PRIVATE_CFLAGS) $$(call host-path,$$(PRIVATE_SRC)) -o $$(call host-path,$$(PRIVATE_OBJ)) \
	$$(call cmd-convert-deps,$$(PRIVATE_DEPS))
endef