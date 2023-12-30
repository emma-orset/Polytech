import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';
import 'no_match_search_model.dart';
export 'no_match_search_model.dart';

class NoMatchSearchWidget extends StatefulWidget {
  const NoMatchSearchWidget({Key? key}) : super(key: key);

  @override
  _NoMatchSearchWidgetState createState() => _NoMatchSearchWidgetState();
}

class _NoMatchSearchWidgetState extends State<NoMatchSearchWidget> {
  late NoMatchSearchModel _model;

  @override
  void setState(VoidCallback callback) {
    super.setState(callback);
    _model.onUpdate();
  }

  @override
  void initState() {
    super.initState();
    _model = createModel(context, () => NoMatchSearchModel());
  }

  @override
  void dispose() {
    _model.maybeDispose();

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Align(
      alignment: AlignmentDirectional(0.0, -1.0),
      child: Padding(
        padding: EdgeInsetsDirectional.fromSTEB(0.0, 2.0, 0.0, 0.0),
        child: Text(
          'No items match your search. \nModify your search criteria or add media.',
          textAlign: TextAlign.center,
          style: FlutterFlowTheme.of(context).bodyMedium,
        ),
      ),
    );
  }
}
