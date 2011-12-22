


MACRO(NORMALIZE_VERSION _requested_version _normalized_version)
    STRING(REGEX MATCH "[^0-9]*[0-9]+\\.[0-9]+\\.[0-9]+.*" _threePartMatch "${_requested_version}")
    if (_threePartMatch)
    # parse the parts of the version string
        STRING(REGEX REPLACE "[^0-9]*([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" _major_vers "${_requested_version}")
        STRING(REGEX REPLACE "[^0-9]*[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1" _minor_vers "${_requested_version}")
        STRING(REGEX REPLACE "[^0-9]*[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" _patch_vers "${_requested_version}")
    else (_threePartMatch)
        STRING(REGEX REPLACE "([0-9]+)\\.[0-9]+" "\\1" _major_vers "${_requested_version}")
        STRING(REGEX REPLACE "[0-9]+\\.([0-9]+)" "\\1" _minor_vers "${_requested_version}")
        set(_patch_vers "0")
    endif (_threePartMatch)

    # compute an overall version number which can be compared at once
    MATH(EXPR ${_normalized_version} "${_major_vers}*10000 + ${_minor_vers}*100 + ${_patch_vers}")
ENDMACRO(NORMALIZE_VERSION)

MACRO(CHECK_RANGE_INCLUSIVE_LOWER _lower_limit _value _upper_limit _ok)
   if (${_value} LESS ${_lower_limit})
      set( ${_ok} FALSE )
  elseif (${_value} EQUAL ${_lower_limit})
      set( ${_ok} TRUE )
  elseif (${_value} EQUAL ${_upper_limit})
      set( ${_ok} FALSE )
  elseif (${_value} GREATER ${_upper_limit})
      set( ${_ok} FALSE )
  else (${_value} LESS ${_lower_limit})
      set( ${_ok} TRUE )
  endif (${_value} LESS ${_lower_limit})
ENDMACRO(CHECK_RANGE_INCLUSIVE_LOWER)

MACRO(ENSURE_VERSION requested_version found_version var_too_old)
    NORMALIZE_VERSION( ${requested_version} req_vers_num )
    NORMALIZE_VERSION( ${found_version} found_vers_num )

    if (found_vers_num LESS req_vers_num)
        set( ${var_too_old} FALSE )
    else (found_vers_num LESS req_vers_num)
        set( ${var_too_old} TRUE )
    endif (found_vers_num LESS req_vers_num)

ENDMACRO(ENSURE_VERSION)

MACRO(ENSURE_VERSION2 requested_version2 found_version2 var_too_old2)
    ENSURE_VERSION( ${requested_version2} ${found_version2} ${var_too_old2})
ENDMACRO(ENSURE_VERSION2)

MACRO(ENSURE_VERSION_RANGE min_version found_version max_version var_ok)
    NORMALIZE_VERSION( ${min_version} req_vers_num )
    NORMALIZE_VERSION( ${found_version} found_vers_num )
    NORMALIZE_VERSION( ${max_version} max_vers_num )

    CHECK_RANGE_INCLUSIVE_LOWER( ${req_vers_num} ${found_vers_num} ${max_vers_num} ${var_ok})
ENDMACRO(ENSURE_VERSION_RANGE)
