(function () {
  var api;

  var attrPrefix = "hx-target-";

  function startsWith(str, prefix) {
    return str.substring(0, prefix.length) === prefix;
  }

  function getRespCodeTarget(elt, respCodeNumber) {
    if (!elt || !respCodeNumber) return null;

    var respCode = respCodeNumber.toString();

    var attrPossibilities = [
      respCode,

      respCode.substr(0, 2) + "*",
      respCode.substr(0, 2) + "x",

      respCode.substr(0, 1) + "*",
      respCode.substr(0, 1) + "x",
      respCode.substr(0, 1) + "**",
      respCode.substr(0, 1) + "xx",

      "*",
      "x",
      "***",
      "xxx",
    ];
    if (startsWith(respCode, "4") || startsWith(respCode, "5")) {
      attrPossibilities.push("error");
    }

    for (var i = 0; i < attrPossibilities.length; i++) {
      var attr = attrPrefix + attrPossibilities[i];
      var attrValue = api.getClosestAttributeValue(elt, attr);
      if (attrValue) {
        if (attrValue === "this") {
          return api.findThisElement(elt, attr);
        } else {
          return api.querySelectorExt(elt, attrValue);
        }
      }
    }

    return null;
  }

  function handleErrorFlag(evt) {
    if (evt.detail.isError) {
      if (htmx.config.responseTargetUnsetsError) {
        evt.detail.isError = false;
      }
    } else if (htmx.config.responseTargetSetsError) {
      evt.detail.isError = true;
    }
  }

  htmx.defineExtension("response-targets", {
    init: function (apiRef) {
      api = apiRef;

      if (htmx.config.responseTargetUnsetsError === undefined) {
        htmx.config.responseTargetUnsetsError = true;
      }
      if (htmx.config.responseTargetSetsError === undefined) {
        htmx.config.responseTargetSetsError = false;
      }
      if (htmx.config.responseTargetPrefersExisting === undefined) {
        htmx.config.responseTargetPrefersExisting = false;
      }
      if (htmx.config.responseTargetPrefersRetargetHeader === undefined) {
        htmx.config.responseTargetPrefersRetargetHeader = true;
      }
    },

    onEvent: function (name, evt) {
      if (
        name === "htmx:beforeSwap" &&
        evt.detail.xhr &&
        evt.detail.xhr.status !== 200
      ) {
        if (evt.detail.target) {
          if (htmx.config.responseTargetPrefersExisting) {
            evt.detail.shouldSwap = true;
            handleErrorFlag(evt);
            return true;
          }
          if (
            htmx.config.responseTargetPrefersRetargetHeader &&
            evt.detail.xhr.getAllResponseHeaders().match(/HX-Retarget:/i)
          ) {
            evt.detail.shouldSwap = true;
            handleErrorFlag(evt);
            return true;
          }
        }
        if (!evt.detail.requestConfig) {
          return true;
        }
        var target = getRespCodeTarget(
          evt.detail.requestConfig.elt,
          evt.detail.xhr.status,
        );
        if (target) {
          handleErrorFlag(evt);
          evt.detail.shouldSwap = true;
          evt.detail.target = target;
        }
        return true;
      }
    },
  });
})();
