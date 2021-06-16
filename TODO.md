- describe how hide the .bs.js hiding using scope 
  - `file[$name$]:*/&&!file[$name$]:app/src//*.bs.js`
  - the seems to live in scopes/foo.xml e.g.
    ```xml
    <component name="DependencyValidationManager">
      <scope name="bs" pattern="file[$name$]:*/&amp;&amp;!file[$name$]:app/src//*.bs.js" />
    </component>
    ```
- consider which of the other deps we might want to add
